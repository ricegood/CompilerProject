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
%token        VOID STRUCT RETURN IF ELSE WHILE FOR BREAK CONTINUE
%token        LOGICAL_OR LOGICAL_AND RELOP EQUOP INCOP DECOP STRUCTOP

/* string, int, id */
%token<stringVal>   CHAR_CONST STRING
%token<intVal>      INTEGER_CONST
%token<idptr>       ID
%token<declptr>     TYPE

/* decl */
%type<declptr>      struct_specifier func_decl param_list param_decl def_list def compound_stmt local_defs stmt_list stmt unary

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
        : type_specifier pointers ID ';' { printf("ext_def;\n"); }
        | type_specifier pointers ID '[' const_expr ']' ';'
        | func_decl ';'
        | type_specifier ';'
        | func_decl
        {
            pushscope();
            pushstelist($1->formalswithreturnid);
            printscopestack();
            is_func_decl = 1;
            block_number = 0;
        }
        compound_stmt
        {
            is_func_decl = 0;
            block_number = 0;
            struct ste *pop = popscope();
            printscopestack();
            // [TODO] delete pop using loop (for prevent from memory leak)
            // delete hash table id also!?
        }

type_specifier
        : TYPE { printTypeDecl($1); }
        | VOID
        | struct_specifier { REDUCE("type_specifier => struct_specifier\n"); }

struct_specifier
        : STRUCT ID '{'
        {
            pushscope();
            printscopestack();
        }
        def_list
        {
            printscopestack();
            struct ste *fields = popscope();
            printscopestack();
            declare($2, ($<declptr>$ = makestructdecl(fields)));
            printscopestack();
        }
        '}'
        {
            $$ = $<declptr>6;
        }
        | STRUCT ID
        {
            struct decl *decl_ptr = findcurrentdecl($2);
            if(decl_ptr != NULL && (check_is_struct_type(decl_ptr) == 1)){
                $$ = decl_ptr;
                //printf("this is struct type\n");
            }
            else {
                $$ = NULL;
                printf("ERROR : this is not struct type\n");
            }
        }

func_decl
        : type_specifier pointers ID '(' ')'
        {
            struct decl *procdecl = makeprocdecl();
            declare($3, procdecl);
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
        | type_specifier pointers ID '(' VOID ')'
        {
            // what is VOID???????
        }
        | type_specifier pointers ID '(' 
        {
            struct decl *procdecl = makeprocdecl();
            declare($3, procdecl);
            pushscope(); /* for collecting formals */
            declare(returnid, $1);
            $<declptr>$ = procdecl;
        }
        param_list ')'
        {
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
                printf("ERROR : this is not struct\n");
            
            $$ = procdecl; 
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
            if ($2 == 0) // no pointer
                declare($3, $$ = makevardecl($1));
            else // pointer
                declare($3, $$ = makevardecl(makeptrdecl($1)));
            printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']'
        {
            if ($2 == 0) // no pointer
                declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
            else // pointer
                declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            
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
            if ($2 == 0) // no pointer
                declare($3, $$ = makevardecl($1));
            else // pointer
                declare($3, $$ = makevardecl(makeptrdecl($1)));

            printscopestack();
        }
        | type_specifier pointers ID '[' const_expr ']' ';'
        {
            if ($2 == 0) // no pointer
                declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl($1))));
            else // pointer
                declare($3, $$ = makeconstdecl(makearraydecl($5->value, makevardecl(makeptrdecl($1)))));
            
            printscopestack();
        }
        | type_specifier ';'
        | func_decl ';'

compound_stmt
        : '{' {
            if (!is_func_decl || block_number > 0)
                pushscope();
            block_number++;
            printscopestack();
        }
        local_defs stmt_list '}' {
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

expr_e
        : expr
        | /* empty */

const_expr
        : expr

expr
        : unary '=' expr
        | or_expr

or_expr
        : or_list

or_list
        : or_list LOGICAL_OR and_expr
        | and_expr

and_expr
        : and_list

and_list
        : and_list LOGICAL_AND binary
        | binary

binary
        : binary RELOP binary
        {
            // [TODO] compatible error
            /*
            if (compatible)
                $$ = inttype; // true or false => int type
            else
                printf("ERROR : relop operands are not compatible!\n");
            */
        }
        | binary EQUOP binary
        {
            // [TODO] compatible error
            /*
            if (compatible)
                $$ = inttype; // true or false => int type
            else
                printf("ERROR : EQUOP operands are not compatible!\n");
            */
        }
        | binary '+' binary
        {
            // [TODO] compatible error
            /*
            if (compatible)
                $$ = plustype($1, $3);
            else
                printf("ERROR : '+' operands are not compatible!\n");
            */
        }
        | binary '-' binary
        {
            // [TODO] compatible error
            /*
            if (compatible)
                $$ = plustype($1, $3); // plustype == minustype
            else
                printf("ERROR : '-' operands are not compatible!\n");
            */
        }
        | unary %prec '='
        {
            if ($$)
                $$ = $1->type;
            else {
                printf("ERROR : unary is NULL!\n");
            }
        }

unary
        : '(' expr ')'
        {
            // problem : expr is type decl....
            // unary is just decl...
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
            // [TODO] ERROR : if unary type is char, is it error?
            $$ = $2;
        }
        | '!' unary
        {
            // [TODO] ERROR : if unary type is char, is it error?
            $$ = $2;
        }
        | unary INCOP
        {
            // [TODO] ERROR
            // [TODO] [Q] should I really do '++' function?
            $$ = $1;
        }
        | unary DECOP
        {
            // [TODO] ERROR
            // [TODO] [Q] should I really do '++' function?
            $$ = $1;
        }
        | INCOP unary
        {
            // [TODO] ERROR
            // [TODO] [Q] should I really do '++' function?
            $$ = $2;
        }
        | DECOP unary
        {
            // [TODO] ERROR
            // [TODO] [Q] should I really do '++' function?
            $$ = $2;
        }
        | '&' unary %prec '!'
        {
            // [TODO] get address ???
            // [TODO] ERROR ?
            $$ = $2;
        }
        | '*' unary %prec '!'
        {
            // [TODO] get pointer ???
            // [TODO] ERROR ?
            $$ = $2;
        }
        | unary '[' expr ']'
        {
            $$ = arrayaccess($1, $3);
        }
        | unary '.' ID
        {
            $$ = structaccess($1, $3);
        }
        | unary STRUCTOP ID
        {
            // STRUCTOP = '->'
            // [TODO] [Q] is this for only pointer?
            // if (check_is_pointer($1))
            $$ = structaccess($1, $3);
            // else printf("ERROR : this is not a pointer type!\n");
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
        | args ',' expr

%%

/*  Additional C Codes  */

int yyerror (char* s) {
    fprintf (stderr, "%s\n", s);
}

void REDUCE( char* s) {
    printf("%s\n",s);
}