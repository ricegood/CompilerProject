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
%type<declptr>      ext_def struct_specifier func_decl param_list param_decl def_list def compound_stmt local_defs stmt_list stmt unary

/* type decl */
%type<declptr>      type_specifier expr_e const_expr expr or_expr or_list and_expr and_list binary args

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
            printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']' ';'
        {
            if ($1) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
            printscopestack();
        }
        | func_decl ';'
        {
            //pushscope();
            //pushstelist($1->formalswithreturnid);
            printscopestack();
        }
        | type_specifier ';'
        {
            // [TODO] what here?
        }
        | func_decl
        {   
            if ($1) {
                pushscope();
                pushstelist($1->formalswithreturnid);
                printscopestack();
                is_func_decl = 1;
                block_number = 0;
            }
        }
        compound_stmt
        {
            if ($1) {
                is_func_decl = 0;
                block_number = 0;
                struct ste *pop = popscope();
                printscopestack();
                // [TODO] delete pop using loop (for prevent from memory leak)
                // delete hash table id also!?
            }
        }

type_specifier
        : TYPE
        | VOID
        | struct_specifier

struct_specifier
        : STRUCT ID '{'
        {
            decl *structdecl = makestructdecl(NULL);
            error_found_in_struct_specifier = declare($2, structdecl);
            if (!error_found_in_struct_specifier) {
                pushscope();
                printscopestack();
            }
            $<declptr>$ = structdecl;
        }
        def_list
        {   
            if (!error_found_in_struct_specifier) {
                struct decl *structdecl = $<declptr>4;
                printscopestack();
                struct ste *fields = popscope();
                printscopestack();
                structdecl->fieldlist = fields;
                $<declptr>$ = structdecl;
                printscopestack();
            }
            else
                $<declptr>6 = NULL;
        }
        '}'
        {
            error_found_in_struct_specifier = 0;
            $$ = $<declptr>6;
        }
        | STRUCT ID
        {
            struct decl *decl_ptr = findcurrentdecl($2);
            if(decl_ptr != NULL && (check_is_struct_type(decl_ptr) == 1)){
                $$ = decl_ptr;
            }
            else {
                $$ = NULL;
                printf("ERROR : incomplete type error (this is not struct type)\n");
            }
        }

func_decl
        : type_specifier pointers ID '(' ')'
        {
            if ($1 && !error_found_in_struct_specifier) {
                struct decl *procdecl = makeprocdecl();
                error_found_in_func_decl = declare($3, procdecl);
                if (!error_found_in_func_decl) {
                    pushscope(); /* for collecting formals */
                    declare(returnid, $1);

                    // no formals

                    struct ste *formals;
                    formals = popscope();

                    /* formals->decl is always returnid decl with return type*/
                    procdecl->formalswithreturnid = formals;
                    procdecl->returntype = formals->decl;
                    procdecl->formals = formals->prev; // null in this production
                    
                    /* error ; struct_specifier returns NULL, because this is not a struct*/
                    if (procdecl->returntype == NULL)
                        printf("ERROR : this is not a struct\n");

                    $$ = procdecl;
                }
                else {
                    // ERROR : redeclaration of same variables at same scope!
                    $$ = NULL;
                }
            }
            else
                $$ = NULL;

            error_found_in_func_decl = 0;
        }
        | type_specifier pointers ID '(' VOID ')'
        {
            // [TODO] what is VOID???????
        }
        | type_specifier pointers ID '(' 
        {
            error_found_in_func_decl = 1;
            if ($1 && !error_found_in_struct_specifier) {
                struct decl *procdecl = makeprocdecl();
                error_found_in_func_decl = declare($3, procdecl);
                if (!error_found_in_func_decl) {
                    pushscope(); /* for collecting formals */
                    declare(returnid, $1);
                    $<declptr>$ = procdecl;
                }
            }
        }
        param_list ')'
        {
            if ($1 && !error_found_in_func_decl) {
                struct ste *formals;
                struct decl *procdecl = $<declptr>5;
                formals = popscope();

                /* formals->decl is always returnid decl with return type*/
                procdecl->formalswithreturnid = formals;
                procdecl->returntype = formals->decl;
                procdecl->formals = formals->prev;

                /*
                    // check point (formal list-first)
                    printf("formal list first param = %s\n", procdecl->formals->name->name);
                    printf("formal list second param = %s\n", procdecl->formals->prev->name->name);
                */

                /* error ; struct_specifier returns NULL, because this is not a struct*/
                if (procdecl->returntype == NULL)
                    printf("ERROR : incomplete type error (this is not struct)\n");
                
                $$ = procdecl; 
            }
            else
                $$ = NULL;

            error_found_in_func_decl = 0;
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
            if ($1 && !error_found_in_func_decl) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makevardecl($1));
                else // pointer
                    declare($3, $$ = makevardecl(makeptrdecl($1)));
            }
            else
                $$ = NULL;
            printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']'
        {
            if ($1 && !error_found_in_func_decl) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
            printscopestack();
        }

def_list    /* list of definitions, definition can be type(struct), variable, function */
        : def_list def
        {
            printf("def list!\n");
        }
        | /* empty */

def
        : type_specifier pointers ID ';'
        {
            if ($1 && !error_found_in_struct_specifier) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makevardecl($1));
                else // pointer 
                    declare($3, $$ = makevardecl(makeptrdecl($1)));
            }
            else
                $$ = NULL;
            printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']' ';'
        {
            if ($1 && !error_found_in_struct_specifier) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
            printscopestack();
        }
        | type_specifier ';'
        {
            if ($1 && !error_found_in_struct_specifier) {
                // [TODO] what here?
            }
        }
        | func_decl ';'
        {
            //pushscope();
            //pushstelist($1->formalswithreturnid);
            printscopestack();
        }

compound_stmt
        : '{'
        {
            if (!is_func_decl || block_number > 0)
                pushscope();
            block_number++;
            printscopestack();
        }
        local_defs stmt_list '}'
        {
            block_number--;
            if (!is_func_decl || block_number > 0)
                popscope();
            printscopestack();
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

        }
        | RETURN expr ';'
        {   
            /* return type check */
            if (check_same_type(findcurrentdecl(returnid), $2)) {
                printf("return type is same type!\n");
            } else {
                printf("ERROR : return type error\n");
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
            /* assignment */
            // should have same type (ppt 23p) & not const! (=>check_is_var)
            if ($1 && check_is_var($1) && check_same_type_for_unary($1, $3))
                $$ = $1->type;
            else
                printf("ERROR : assignment value is not same, or LHS value type is not variable!\n");
        }
        | or_expr
        | NULL_TOKEN
        {
            // [TODO]
            $$ = nulltype;
        }

or_expr
        : or_list

or_list
        : or_list LOGICAL_OR and_expr
        {
            /* only for int type */
            if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = inttype;
            else
                printf("ERROR : '||' operator is only for int type!\n");
        }
        | and_expr

and_expr
        : and_list

and_list
        : and_list LOGICAL_AND binary
        {
            /* only for int type */
            if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = inttype;
            else
                printf("ERROR : '&&' operator is only for int type!\n");
        }
        | binary

binary
        : binary RELOP binary
        {
            /* char RELOP char */
            if (check_same_type($1, chartype) && check_same_type($3, chartype))
                $$ = inttype;

            /* int RELOP int */
            else if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = inttype;

            /* ERROR */
            else {
                printf("ERROR : binary RELOP binary is only for int, char type!\n");
                $$ = NULL;
            }
        }
        | binary EQUOP binary
        {
            /* char EQUOP char */
            if (check_same_type($1, chartype) && check_same_type($3, chartype))
                $$ = inttype;

            /* int EQUOP int */
            else if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = inttype;

            /* pointer EQUOP pointer */
            else if (check_is_pointer_type($1) && check_is_pointer_type($3))
                $$ = inttype;

            /* ERROR */
            else {
                printf("ERROR : binary EQUOP binary is only for int, char, pointer type!\n");
                $$ = NULL;
            }
        }
        | binary '+' binary
        {
            // [TODO] is it only okay for int+int ?
            // then, plustype is always inttype ?

            if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = plustype($1, $3);
            else
                printf("ERROR : binary '+' operands are only for integer!\n");
        }
        | binary '-' binary
        {
            // [TODO] is it only okay for int-int ?
            // then, plustype is always inttype ?

            if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = plustype($1, $3);
            else
                printf("ERROR : binary '-' operands are only for integer!\n");
        }
        | unary %prec '='
        {   
            if ($1 && $1->type)
                $$ = $1->type;
            else {
                printf("ERROR : unary is NULL or unary semantic value->type is null!\n");
            }
        }

unary
        : '(' expr ')'
        {
            // [TODO] problem : expr is type decl....
            // unary is just decl...
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
            // [TODO] how about value ?
            $$ = makeconstdecl(chartype);
        }
        | STRING
        {
            // [TODO] how about value ?
            // [Q] is this const ???
            $$ = makeconstdecl(stringtype);
        }
        | ID {
            // find ID
            $$ = findcurrentdecl($1);
            if (!$$)
                printf("ERROR : There is no such ID.\n");
        }
        | '-' unary %prec '!'
        {   
            /* only integer */
            if (check_same_type_for_unary($2, inttype))
                $$ = $2;
            else
                printf("ERROR : '-' operator is only for integer.\n");
        }
        | '!' unary
        {
            /* only for int type */
            if (check_same_type_for_unary($2, inttype))
                $$ = inttype;
            else
                printf("ERROR : '!' operator is only for int type!\n");
        }
        | unary INCOP
        {
            /* only char, integer */
            if (check_same_type_for_unary($1, inttype) || check_same_type_for_unary($1, chartype))
                $$ = $1;
            else
                printf("ERROR : unary INCOP operator is only for char or integer.\n");
        }
        | unary DECOP
        {
            /* only char, integer */
            if (check_same_type_for_unary($1, inttype) || check_same_type_for_unary($1, chartype))
                $$ = $1;
            else
                printf("ERROR : unary DECOP operator is only for char or integer.\n");
        }
        | INCOP unary
        {
            /* only char, integer */
            if (check_same_type_for_unary($2, inttype) || check_same_type_for_unary($2, chartype))
                $$ = $2;
            else
                printf("ERROR : unary INCOP operator is only for char or integer.\n");
        }
        | DECOP unary
        {
            /* only char, integer */
            if (check_same_type_for_unary($2, inttype) || check_same_type_for_unary($2, chartype))
                $$ = $2;
            else
                printf("ERROR : unary DECOP operator is only for char or integer.\n");
        }
        | '&' unary %prec '!'
        {
            // [TODO]
            /*
                if use '&', unary becomes pointer type value.
                ex) int* a -> &a -> int**
                ex2) int a -> &a -> int*
            */
            if (check_is_var($2)) {
                $$ = makeconstdecl(makeptrdecl($2->type));
            }
            else {
                printf("ERROR : Can't use operator '&' for non-variable type value.\n");
            }
            
        }
        | '*' unary %prec '!'
        {
            if (check_is_pointer_type($2->type)) {
                $$ = makevardecl($2->ptrto);
            }
            else {
                printf("ERROR : Can't use point operator '*' for non-pointer value.\n");
            }
        }
        | unary '[' expr ']'
        {
            $$ = arrayaccess($1, $3);
        }
        | unary '.' ID
        {
            /* This is only for structure type on $1 */
            if (!check_is_pointer_type($1->type)){
                $$ = structaccess($1, $3);
            }
            else {
                printf("ERROR : this is a POINTER to structure type!\n");
            }
        }
        | unary STRUCTOP ID
        {
            // [TODO] this is only for pointer to structure type on $1
            if (check_is_pointer_type($1->type)){
                $$ = structaccess($1, $3);
            }
            else {
                printf("ERROR : this is not a pointer to structure type!\n");
            }
        }
        | unary '(' args ')'
        {
            if (check_is_proc($1))
                $$ = check_function_call($1, $3);
            else
                printf ("ERROR : this is not a function!\n");
        }
        | unary '(' ')'
        {
            if (check_is_proc($1))
                $$ = check_function_call($1, NULL);
            else
                printf ("ERROR : this is not a function!\n");
        }

args    /* actual parameters(function arguments) transferred to function */
        : expr
        {
            // expr semantic value type is TYPEDECL.
            //$$ = $1;
            $$ = makeconstdecl($1);
        }
        | args ',' expr
        {
            // [TODO] args,expr 에서 올라오는건 TYPE 이라 next 연결 못함..
            $1->next = makeconstdecl($3);
            $$ = $1;
        }

%%

/*  Additional C Codes  */

int yyerror (char* s) {
    fprintf (stderr, "%s\n", s);
}

void REDUCE( char* s) {
    printf("%s\n",s);
}