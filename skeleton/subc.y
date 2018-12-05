%{
/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */

#include "subc.h"
#include "subc.tab.h"

int    yylex ();
int    yyerror (char* s);
void   REDUCE(char* s);

int num_of_err_message = 0; /* for print only 1 error for 1 line */

/* flag for subc.y */
int is_func_decl = 0; /* for scope stack management about block inside of function */
int block_number = 0; /* for scope stack management about block inside of function */
int start_param_parsing = 1; /* for prevent from conflicts. */
%}

/* yylval types */
%union {
    int intVal;
    char *stringVal;
    struct id *idptr;
    struct decl *declptr;
    struct ste *steptr;
}

/* Precedences and Associativities */
%left   ','
%right  '='
%left   LOGICAL_OR
%left   LOGICAL_AND
%left   '&'
%left   EQUOP
%left   RELOP
%left   '+' '-'
%left   '*'
%right  '!' INCOP DECOP
%left   '[' ']' '(' ')' '.' STRUCTOP
%nonassoc   ELSE

/* Tokens and Types */
/* Tokens */
%token        STRUCT RETURN IF ELSE WHILE FOR BREAK CONTINUE
%token        LOGICAL_OR LOGICAL_AND RELOP EQUOP INCOP DECOP STRUCTOP

/* string, int, id */
%token<stringVal>   CHAR_CONST STRING
%token<intVal>      INTEGER_CONST
%token<idptr>       ID
%token<declptr>     TYPE VOID NULL_TOKEN

/* decl */
%type<declptr>      ext_def struct_specifier func_decl param_list param_decl def compound_stmt unary

/* type decl */
%type<declptr>      type_specifier const_expr expr or_expr or_list and_expr and_list binary args

%type<intVal>       pointers;

%%

program
        : ext_def_list
        ;

ext_def_list
        : ext_def_list ext_def
        | /* empty */
        ;

ext_def
        : type_specifier pointers ID ';'
        {
            if ($1) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makevardecl($1));
                else // pointer
                    declare($3, $$ = makevardecl(makeptrdecl($1)));
            }
            else
                $$ = NULL;
        }
        | type_specifier pointers ID '[' unary ']' ';'
        {
            if ($1 && $5) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
        }
        | func_decl ';'
        {   
            /* code generation */
            labelname = $1->id->name;
            LABEL(labelname);
            FUNC_LABEL(labelname, "start");
            FUNC_LABEL(labelname, "final");
            CODE("push_reg fp");
            CODE("pop_reg sp");
            CODE("pop_reg fp");
            CODE("pop_reg pc");
            FUNC_LABEL(labelname, "end");
        }
        | type_specifier ';'
        {
        }
        | func_decl
        {   
            pushscope();
            pushstelist($1->formalswithreturnid);
            is_func_decl = 1;
            block_number = 0;

            /* code generation */
            labelname = $1->id->name;
            top->sumofsize = 0; // reset after pushstelist
            LABEL(labelname);
        }
        compound_stmt
        {
            is_func_decl = 0;
            block_number = 0;
            struct ste *pop = popscope();

            /* [TODO] delete pop using loop (for prevent from memory leak) */

            /* code generation */
            labelname = $1->id->name;
            FUNC_LABEL(labelname, "final");
            CODE("push_reg fp");
            CODE("pop_reg sp");
            CODE("pop_reg fp");
            CODE("pop_reg pc");
            FUNC_LABEL(labelname, "end");
            if (strcmp(labelname,"main") == 0) {
                // in main function, set global variable memory size
                printf("\tLglob. data %d\n", globalscope->sumofsize);
            }
        }

type_specifier
        : TYPE
        | VOID
        | struct_specifier

struct_specifier
        : STRUCT ID '{'
        {
            pushscope();
        }
        def_list
        {
            struct ste *fields = popscope();
            decl *structdecl = makestructdecl(fields);
            declare($2, structdecl);
            $<declptr>$ = structdecl;
        }
        '}'
        {
            $$ = $<declptr>6;
        }
        | STRUCT ID
        {   
            struct decl *decl_ptr = findstructdecl($2);
            if (check_is_struct_type(decl_ptr)) {
                $$ = decl_ptr;
            }
            else {
                $$ = NULL;
                ERROR("incomplete type error");
            }
        }

func_decl
        : type_specifier pointers ID '(' ')'
        {
            struct decl *procdecl = makeprocdecl();
            if ($1) {
                declare($3, procdecl);
            }
            pushscope(); /* for collecting formals */

            if ($2 == 0) // no pointer
                declare(returnid, $1);
            else // pointer
                declare(returnid, makeptrdecl($1));

            /* no formals */
            struct ste *formals;
            formals = popscope();

            /* formals->decl is always returnid decl with return type*/
            procdecl->formalswithreturnid = formals;
            procdecl->returntype = formals->decl;
            procdecl->formals = formals->prev; // null in this production
            
            /* error ; struct_specifier returns NULL, because this is not a struct*/
            if (procdecl->returntype == NULL)
                ERROR("incomplete type error");

            $$ = procdecl;
        }
        | type_specifier pointers ID '(' VOID ')'
        {
            struct decl *procdecl = makeprocdecl();
            if ($1) {
                declare($3, procdecl);
            }
            pushscope(); /* for collecting formals */

            if ($2 == 0) // no pointer
                declare(returnid, $1);
            else // pointer
                declare(returnid, makeptrdecl($1));

            /* no formals */
            struct ste *formals;
            formals = popscope();

            /* formals->decl is always returnid decl with return type*/
            procdecl->formalswithreturnid = formals;
            procdecl->returntype = formals->decl;
            procdecl->formals = formals->prev; // null in this production
            
            /* error ; struct_specifier returns NULL, because this is not a struct*/
            if (procdecl->returntype == NULL)
                ERROR("incomplete type error");

            $$ = procdecl;
        }
        | type_specifier pointers ID '(' param_list ')'
        {   
            struct ste *formals;
            struct ste *returntype;
            struct decl *procdecl;
            formals = popscope();
            procdecl = makeprocdecl();

            if ($1) {
                declare($3, procdecl);
            }

            pushscope(); /* for collecting returnid */
            if ($2 == 0) // no pointer
                declare(returnid, $1);
            else // pointer
                declare(returnid, makeptrdecl($1));
            returntype = popscope();
            returntype->prev = formals;
            formals = returntype;

            /* formals->decl is always returnid decl with return type*/
            procdecl->formalswithreturnid = formals;
            procdecl->returntype = formals->decl;
            procdecl->formals = formals->prev;

            /* error ; struct_specifier returns NULL, because this is not a struct*/
            if (procdecl->returntype == NULL)
                ERROR("incomplete type error");

            $$ = procdecl; 
            start_param_parsing = 1;
        }

pointers
        : '*' { $$ = 1; }
        | /* empty */ { $$ = 0; }

param_list  /* list of formal parameter declaration */
        : param_decl
        | param_list ',' param_decl

param_decl  /* formal parameter declaration */
        : type_specifier pointers ID
        {      
            if (start_param_parsing) {
                pushscope();
                start_param_parsing = 0;
            }

            if ($1) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makevardecl($1));
                else // pointer
                    declare($3, $$ = makevardecl(makeptrdecl($1)));
            }
            else
                $$ = NULL;
        }
        | type_specifier pointers ID '[' unary ']'
        {
            if (start_param_parsing) {
                pushscope();
                start_param_parsing = 0;
            }

            if ($1 && $5) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
        }

def_list    /* list of definitions, definition can be type(struct), variable, function */
        : def_list def
        {
        }
        | /* empty */

def
        : type_specifier pointers ID ';'
        {
            if ($1) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makevardecl($1));
                else // pointer 
                    declare($3, $$ = makevardecl(makeptrdecl($1)));
            }
            else
                $$ = NULL;
        }
        | type_specifier pointers ID '[' unary ']' ';'
        {
            if ($1 && $5) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
        }
        | type_specifier ';'
        | func_decl ';'
        {
            /* code generation */
            labelname = $1->id->name;
            LABEL(labelname);
            FUNC_LABEL(labelname, "start");
            FUNC_LABEL(labelname, "final");
            CODE("push_reg fp");
            CODE("pop_reg sp");
            CODE("pop_reg fp");
            CODE("pop_reg pc");
            FUNC_LABEL(labelname, "end");
        }

compound_stmt
        : '{'
        {
            if (!is_func_decl || block_number > 0)
                pushscope();
            block_number++;
        }
        local_defs
        {
            /* code generation */
            printf("\tshift_sp %d\n", top->sumofsize);
            FUNC_LABEL(labelname, "start");
        }
        stmt_list '}'
        {
            block_number--;
            if (!is_func_decl || block_number > 0)
                popscope();
        }

local_defs  /* local definitions, of which scope is only inside of compound statement */
        :   def_list

stmt_list
        : stmt_list stmt
        | /* empty */

stmt
        : expr ';'
        | compound_stmt
        | RETURN ';'
        {
            if (!check_same_type(findcurrentdecl(returnid), voidtype)) {
                /* return type check */
                ERROR("return type was not matched");
            }
        }
        | RETURN expr ';'
        {   
            if ($2 && !check_same_type(findcurrentdecl(returnid), $2)) {
                /* return type check */
                ERROR("return type was not matched");
            }
        }
        | ';'
        | IF '(' expr ')' stmt
        | IF '(' expr ')' stmt ELSE stmt
        | WHILE '(' expr ')' stmt
        | FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt
        | BREAK ';'
        | CONTINUE ';'

/* binary~expr~args semantic value type = type decl */

expr_e
        : expr
        | /* empty */

const_expr
        : expr

expr
        : unary '=' expr
        {
            /* assignment operation */
            /* should have same type (ppt 23p) & not const! (=>check_is_var) */
            if ($1) {
                if (check_is_var($1)) {
                    if (check_same_type_for_unary($1, $3))
                        $$ = $1->type;
                    else {
                        if ($3 == nulltype) 
                            ERROR("RHS is not a const or variable");
                        else
                            ERROR("LHS and RHS are not same type");
                        $$ = NULL;
                    }
                }
                else {
                    ERROR("LHS is not a variable");
                    $$ = NULL;
                }
            }
            else
                $$ = NULL;
        }
        | or_expr

or_expr
        : or_list

or_list
        : or_list LOGICAL_OR and_expr
        {
            if ($1 && $3) {
                /* only for int type */
                if (check_same_type($1, inttype) && check_same_type($3, inttype))
                    $$ = inttype;
                else
                    ERROR("not int type");
            }
            else
                $$ = NULL;
        }
        | and_expr

and_expr
        : and_list

and_list
        : and_list LOGICAL_AND binary
        {
            if ($1 && $3) {
                /* only for int type */
                if (check_same_type($1, inttype) && check_same_type($3, inttype))
                    $$ = inttype;
                else
                    ERROR("not int type");
            }
            else
                $$ = NULL;
        }
        | binary

binary
        : binary RELOP binary
        {   
            if (!(check_same_type($1, chartype) || check_same_type($1, inttype)) || !(check_same_type($3, chartype) || check_same_type($3, inttype))) {
                ERROR("not int or char type");
            }

            /* char RELOP char or int RELOP int */
            else if (check_same_type($1, $3))
                $$ = inttype;

            /* ERROR */
            else {
                ERROR("not comparable");
            }
        }
        | binary EQUOP binary
        {   
            if (check_is_array($1) && check_is_array($3) && check_same_type($1->elementvar->type, $3->elementvar->type)) {
                /* for array EQUOP array */
                $$ = inttype;
            }

            else if (!(check_same_type($1, chartype) || check_same_type($1, inttype) || check_is_pointer_type($1) || check_is_array($1)) || !(check_same_type($3, chartype) || check_same_type($3, inttype) || check_is_pointer_type($3) || check_is_array($3))) {
                ERROR("not int or char type");
            }

            /* char EQUOP char or int EQUOP int or pointer(same type) EQUOP pointer(same type) */
            else if (check_same_type($1, $3))
                $$ = inttype;

            /* ERROR */
            else {
                ERROR("not comparable");
            }
        }
        | binary '+' binary
        {
            /* only for int+int */
            if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = plustype($1, $3);
            else {
                ERROR("not int type");
                $$ = NULL;
            }
        }
        | binary '-' binary
        {
            /* only for int+int */
            if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = plustype($1, $3);
            else {
                ERROR("not int type");
                $$ = NULL;
            }
        }
        | unary %prec '='
        {   
            if ($1 && $1->type)
                $$ = $1->type;
            else if ($1 == nulltype) {
                $$ = nulltype;
            }
            else {
                $$ = NULL;
            }
        }

unary
        : '(' expr ')'
        {
            /* expr is type decl and unary is just decl => Make constdecl to solve this problem */
            $$ = makeconstdecl($2);
        }
        | '(' unary ')' 
        {
            $$ = $2;
        }
        | INTEGER_CONST
        {
            $$ = makeintconstdecl(inttype, $1);
        }
        | CHAR_CONST
        {   
            $$ = makeconstdecl(chartype);
        }
        | STRING
        {
            $$ = makeconstdecl(stringtype);
        }
        | ID {
            /* find ID */
            $$ = findcurrentdecl($1);
            if (!$$)
                ERROR("not declared");

            /* code generation */
            // push address
            switch (check_variable_scope($$)) {
                case GLOBAL:
                    CODE("push_const Lglob");
                    printf("\tpush_const %d\n", $$->offset);
                    CODE("add");
                    break;

                case PARAM:
                    CODE("push_reg FP");
                    printf("\tpush_const %d\n", ($$->offset) - ($$->check_param) - 1);
                    CODE("add");
                    break;

                case LOCAL:
                    CODE("push_reg FP");
                    printf("\tpush_const %d\n", 1 + $$->offset);
                    CODE("add");
                    break;

                default:
                    break;
            }
        }
        | '-' unary %prec '!'
        {   
            /* only integer */
            if (check_same_type_for_unary($2, inttype))
                $$ = $2;
            else {
                ERROR("not int type");
                $$ = NULL;
            }
        }
        | '!' unary
        {
            /* only for int type */
            if (check_same_type_for_unary($2, inttype))
                $$ = inttype;
            else {
                ERROR("not int type");
                $$ = NULL;
            }
        }
        | unary INCOP
        {
            /* only char, integer */
            if (check_same_type_for_unary($1, inttype) || check_same_type_for_unary($1, chartype))
                $$ = $1;
            else {
                ERROR("not int or char type");
                $$ = NULL;
            }
        }
        | unary DECOP
        {
            /* only char, integer */
            if (check_same_type_for_unary($1, inttype) || check_same_type_for_unary($1, chartype))
                $$ = $1;
            else {
                ERROR("not int or char type");
                $$ = NULL;
            }
        }
        | INCOP unary
        {
            /* only char, integer */
            if (check_same_type_for_unary($2, inttype) || check_same_type_for_unary($2, chartype))
                $$ = $2;
            else {
                ERROR("not int or char type");
                $$ = NULL;
            }
        }
        | DECOP unary
        {
            /* only char, integer */
            if (check_same_type_for_unary($2, inttype) || check_same_type_for_unary($2, chartype))
                $$ = $2;
            else {
                ERROR("not int or char type");
                $$ = NULL;
            }
        }
        | '&' unary %prec '!'
        {
            /*
                if use '&', unary becomes pointer type value.
                ex) int* a -> &a -> int**
                ex2) int a -> &a -> int*
            */
            if ($2) {
                if (check_is_var($2)) {
                    /* '&value' can't be LHS */
                    $$ = makeconstdecl(makeptrdecl($2->type));
                }
                else {
                    ERROR("not variable");
                    $$ = NULL;
                }
            }
            else
                $$ = NULL;
            
        }
        | '*' unary %prec '!'
        {   
            if($2) {
                if (check_is_pointer_type($2->type)) {
                    $$ = makevardecl($2->type->ptrto);
                }
                else {
                    ERROR("not a pointer");
                    $$ = NULL;
                }
            }
            else
                $$ = NULL;
        }
        | unary '[' expr ']'
        {
            if ($1)
                $$ = arrayaccess($1, $3);
        }
        | unary '.' ID
        {
            /* This is only for structure type on $1 */
            if ($1 && !check_is_pointer_type($1->type)){
                $$ = structaccess($1, $3);
            }
            else {
                ERROR("variable is not struct");
                $$ = NULL;
            }
        }
        | unary STRUCTOP ID
        {
            /* this is only for pointer to structure type on $1 */
            if ($1 && check_is_pointer_type($1->type)){
                $$ = structaccess($1, $3);
            }
            else {
                ERROR("not a pointer");
                $$ = NULL;
            }
        }
        | unary '(' args ')'
        {
            /*
                function call!
                args pointer last pushed args.
                args->elementvar field pointer first pushed args.
            */

            if (check_is_proc($1)) {
                if ($3)
                    $$ = check_function_call($1, $3->elementvar);
            }
            else
                ERROR ("not a function");

            /* code generation */
            printf("function call!\n");
        }
        | unary '(' ')'
        {
            if (check_is_proc($1))
                $$ = check_function_call($1, NULL);
            else
                ERROR ("not a function");

            /* code generation */
            printf("function call!\n");
        }
        | NULL_TOKEN
        {
            $$ = nulltype;
        }

args    /* actual parameters(function arguments) transferred to function */
        : expr
        {
            /* expr semantic value type is TYPEDECL */
            $$ = makeconstdecl($1);
            $$->elementvar = $$; /* to save first args pointer. */
        }
        | args ',' expr
        {
            if ($$ && $1) {
                $1->next = makeconstdecl($3);
                $1->next->elementvar = $$->elementvar;
                $$ = $1->next;
            }
            else
                $$ = NULL;
        }

%%

/*  Additional C Codes  */

int yyerror (char* s) {
    fprintf (stderr, "%s\n", s);
}

void REDUCE(char* s) {
    printf("%s\n",s);
}

void ERROR(char* s) {
    int lineno = read_line();

    /* print only 1 error message by 1 line */
    if (num_of_err_message < lineno) {
        printf("%s:%d: error:%s\n", filename, read_line(), s);
        num_of_err_message = lineno;
    }
}

void CODE(char *s) {
    printf("\t%s\n",s);
}

void LABEL(char *s) {
    printf("%s:\n",s);
}

void FUNC_LABEL(char *func_name, char *label) {
    printf("%s_%s:\n", func_name, label);
}