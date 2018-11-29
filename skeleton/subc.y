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

int num_of_err_message = 0; // print only 1 error for 1 line

/* flag for subc.y */
int is_func_decl = 0;
int block_number = 0;
int error_found_in_func_decl = 0;
int error_found_in_struct_specifier = 0; /* for def_list & error_found flag */
//int return_type_error = 0; /* It can work because func inside func is impossible. no synchronization problem. */
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
            //printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']' ';'
        {
            if ($1 && $5) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
            //printscopestack();
        }
        | func_decl ';'
        {
            //printscopestack();
            error_found_in_func_decl = 0;
            current_parsing_function_ste = NULL;
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
                //printscopestack();
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
                //printscopestack();
                // [TODO] delete pop using loop (for prevent from memory leak)
                // delete hash table id also!?
            }

            /*

            // if return type is wrong, rollback here (remove top ste)
            if (return_type_error) {
                // [TODO] memory leak (free wrong_func_decl)
                struct ste* wrong_func_decl = popste();
                rollback_struct_of($1);
            }

            */
            // reset value
            error_found_in_func_decl = 0;
            //return_type_error = 0;
            current_parsing_function_ste = NULL;
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
                //printscopestack();
            }
            $<declptr>$ = structdecl;
        }
        def_list
        {   
            if (!error_found_in_struct_specifier) {
                struct decl *structdecl = $<declptr>4;
                //printscopestack();
                struct ste *fields = popscope();
                //printscopestack();
                structdecl->fieldlist = fields;
                $<declptr>$ = structdecl;
                //printscopestack();
            }
            else
                $<declptr>$ = NULL;
        }
        '}'
        {
            error_found_in_struct_specifier = 0;
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
            if ($1 && !error_found_in_struct_specifier) {
                struct decl *procdecl = makeprocdecl();
                error_found_in_func_decl = declare($3, procdecl);
                if (!error_found_in_func_decl) {
                    current_parsing_function_ste = top->data; // get last inserted ste (= procdecl ste)
                    pushscope(); /* for collecting formals */

                    if ($2 == 0) // no pointer
                        declare(returnid, $1);
                    else // pointer
                        declare(returnid, makeptrdecl($1));

                    // no formals

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
                else {
                    // ERROR : redeclaration of same variables at same scope!
                    $$ = NULL;
                }
            }
            else
                $$ = NULL;
        }
        | type_specifier pointers ID '(' VOID ')'
        {
            // [TODO] what is VOID???????
            if ($1 && !error_found_in_struct_specifier) {
                struct decl *procdecl = makeprocdecl();
                error_found_in_func_decl = declare($3, procdecl);
                if (!error_found_in_func_decl) {
                    current_parsing_function_ste = top->data; // get last inserted ste (= procdecl ste)
                    pushscope(); /* for collecting formals */

                    if ($2 == 0) // no pointer
                        declare(returnid, $1);
                    else // pointer
                        declare(returnid, makeptrdecl($1));

                    // no formals

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
                else {
                    // ERROR : redeclaration of same variables at same scope!
                    $$ = NULL;
                }
            }
            else
                $$ = NULL;
        }
        | type_specifier pointers ID '(' 
        {
            error_found_in_func_decl = 1;
            if ($1 && !error_found_in_struct_specifier) {
                struct decl *procdecl = makeprocdecl();
                error_found_in_func_decl = declare($3, procdecl);
                if (!error_found_in_func_decl) {
                    pushscope(); /* for collecting formals */

                    if ($2 == 0) // no pointer
                        declare(returnid, $1);
                    else // pointer
                        declare(returnid, makeptrdecl($1));

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
                    ERROR("incomplete type error");
                
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
            //printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']'
        {
            if ($1 && $5 && !error_found_in_func_decl) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
            //printscopestack();
        }

def_list    /* list of definitions, definition can be type(struct), variable, function */
        : def_list def
        {
            //printf("def list!\n");
        }
        | /* empty */

def
        : type_specifier pointers ID ';'
        {
            if ($1 && !error_found_in_struct_specifier && !error_found_in_func_decl) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makevardecl($1));
                else // pointer 
                    declare($3, $$ = makevardecl(makeptrdecl($1)));
            }
            else
                $$ = NULL;
            //printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']' ';'
        {
            if ($1 && $5 && !error_found_in_struct_specifier && !error_found_in_func_decl) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            }
            else
                $$ = NULL;
            //printscopestack();
        }
        | type_specifier ';'
        {
            if ($1 && !error_found_in_struct_specifier && !error_found_in_func_decl) {
                // [TODO] what here?
            }
        }
        | func_decl ';'
        {
            //printscopestack();
            error_found_in_func_decl = 0;
            current_parsing_function_ste = NULL;
        }

compound_stmt
        : '{'
        {
            // **[TODO] add error_found_in_func_decl flag in this option!!
            if (!error_found_in_func_decl) {
                if (!is_func_decl || block_number > 0)
                    pushscope();
                block_number++;
                //printscopestack();
            }
        }
        local_defs stmt_list '}'
        {
            if (!error_found_in_func_decl) {
                block_number--;
                if (!is_func_decl || block_number > 0)
                    popscope();
                //printscopestack();
            }
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
            if ($2 && !error_found_in_func_decl) {
                /* return type check */
                if (check_same_type(findcurrentdecl(returnid), $2)) {
                    //return_type_error = 0;
                } else {
                    ERROR("return type was not matched");
                    //return_type_error = 1;
                }
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
                    ERROR("not comparable");
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
                    ERROR("not comparable");
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
            if (!(check_same_type($1, chartype) || check_same_type($1, inttype) || check_is_pointer_type($1)) || !(check_same_type($3, chartype) || check_same_type($3, inttype) || check_is_pointer_type($3))) {
                ERROR("not int or char or pointer type");
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
            // [TODO] is it only okay for int+int ?
            // then, plustype is always inttype ?

            if (check_same_type($1, inttype) && check_same_type($3, inttype))
                $$ = plustype($1, $3);
            else {
                ERROR("not int type");
                $$ = NULL;
            }
        }
        | binary '-' binary
        {
            // [TODO] is it only okay for int-int ?
            // then, plustype is always inttype ?

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
                // ERROR("ERROR : unary is NULL or unary semantic value->type is null!");
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
                ERROR("not declared");
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
            // [TODO]
            /*
                if use '&', unary becomes pointer type value.
                ex) int* a -> &a -> int**
                ex2) int a -> &a -> int*
            */
            if ($2) {
                if (check_is_var($2)) {
                    // it can't be RHS
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
            // this is only for pointer to structure type on $1
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
                args pointer last pushed args.
                args->elementvar field pointer first pushed args.
            */

            if (check_is_proc($1)) {
                if ($3)
                    $$ = check_function_call($1, $3->elementvar);
            }
            else
                ERROR ("not a function");
        }
        | unary '(' ')'
        {
            if (check_is_proc($1))
                $$ = check_function_call($1, NULL);
            else
                ERROR ("not a function");
        }
        | NULL_TOKEN
        {
            // [TODO]
            $$ = nulltype;
        }

args    /* actual parameters(function arguments) transferred to function */
        : expr
        {
            // expr semantic value type is TYPEDECL.
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