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
int is_array_decl = 0; /* for prevent from printing 'push_const int' */
int is_if_stmt = 0; /* for printing label in if-else statement */
int no_fetch = 0; /* no fetch flag for INCOP, DECOP in unary->ID production */
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
%token        LOGICAL_OR LOGICAL_AND INCOP DECOP STRUCTOP

/* string, int, id */
%token<stringVal>   STRING EQUOP RELOP
%token<intVal>      CHAR_CONST INTEGER_CONST
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
        | type_specifier pointers ID '[' 
        {
            is_array_decl = 1; // prevent from printing 'push_const' in unary
        }
        unary
        {
            is_array_decl = 0; // reset
        }
        ']' ';'
        {
            if ($1 && $6) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($6->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($6->value, makevardecl(makeptrdecl($1)))));
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
        | type_specifier pointers ID '['
        {
            is_array_decl = 1; // prevent from printing 'push_const' in unary
        }
        unary
        {
            is_array_decl = 0; // reset
        }
        ']'
        {
            if (start_param_parsing) {
                pushscope();
                start_param_parsing = 0;
            }

            if ($1 && $6) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($6->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($6->value, makevardecl(makeptrdecl($1)))));
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
        | type_specifier pointers ID '['
        {
            is_array_decl = 1; // prevent from printing 'push_const' in unary
        }
        unary
        {
            is_array_decl = 0; // reset
        }
        ']' ';'
        {
            if ($1 && $6) {
                if ($2 == 0) // no pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($6->value, makevardecl($1))));
                else // pointer
                    declare($3, $$ = makeconstdecl(makearraydecl($6->value, makevardecl(makeptrdecl($1)))));
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
            if (is_func_decl && block_number == 1) {
                printf("\tshift_sp %d\n", top->sumofsize);
                FUNC_LABEL(labelname, "start");
            }
            else if (!is_if_stmt) {
                printf("label_%d:\n", use_label());
            }

            is_if_stmt = 0; // reset
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
        | RETURN return_code_gen ';'
        {
            if (!check_same_type(findcurrentdecl(returnid), voidtype)) {
                /* return type check */
                ERROR("return type was not matched");
            }

            /* code generation */
            CODE("push_const 0"); // no return expr, so return value = 0
            CODE("assign");
            printf("\tjump %s_final\n", labelname);
        }
        | RETURN return_code_gen expr ';'
        {   
            if ($3 && !check_same_type(findcurrentdecl(returnid), $3)) {
                /* return type check */
                ERROR("return type was not matched");
            }

            /* code generation */
            CODE("assign"); // assign return value (fp-2)
            printf("\tjump %s_final\n", labelname);
        }
        | ';'
        | IF if_code_gen '(' expr ')' if_branch_code_gen stmt
        {   
            printf("label_%d:\n", use_label());
        }
        | IF if_code_gen '(' expr ')' if_branch_code_gen stmt ELSE
        {   
            printf("\tjump label_%d\n", new_label());
        }
        stmt
        {
            printf("label_%d:\n", use_label());
        }
        | WHILE '(' expr ')' stmt
        | FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt
        | BREAK ';'
        | CONTINUE ';'

return_code_gen : /* empty */
        {
            /* code generation */
            CODE("push_reg fp");
            CODE("push_const -1");
            CODE("add"); // return address : fp-1
            CODE("push_const -1");
            CODE("add"); // return value : fp-2
        }

if_code_gen : /* empty */
        {
            /* code generation */
            printf("label_%d:\n", new_label());
            use_label();
        }

if_branch_code_gen : /* empty */
        {
            /* code generation */
            printf("\tbranch_false label_%d\n", new_label());
            is_if_stmt = 1; // prevent from printing label wrongly
        }

expr_e
        : expr
        | /* empty */

const_expr
        : expr

expr
        : unary '='
        {
            /* code generation */
            CODE("push_reg sp");
            CODE("fetch");
        }
        expr
        {
            /* assignment operation */
            /* should have same type (ppt 23p) & not const! (=>check_is_var) */
            if ($1) {
                if (check_is_var($1)) {
                    if (check_same_type_for_unary($1, $4))
                        $$ = $1->type;
                    else {
                        if ($4 == nulltype) 
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


            /* code generation */
            CODE("assign");
            CODE("fetch");
            CODE("shift_sp -1");
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

            /* code generation */
            CODE("or");
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

            /* code generation */
            CODE("and");
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

            /* code generation */
            if (strcmp($2, "<") == 0) {
                CODE("less");
            }
            else if (strcmp($2, "<=") == 0){
                CODE("less_equal");
            }
            else if (strcmp($2, ">") == 0){
                CODE("greater");
            }
            else if (strcmp($2, ">=") == 0){
                CODE("greater_equal");
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

            /* code generation */
            if (strcmp($2, "==") == 0) {
                CODE("equal");
            }
            else {
                CODE("not_equal");
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

            /* code generation */
            CODE("add");
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

            /* code generation */
            CODE("sub");
        }
        | unary %prec '='
        {
            if ($1 && $1->type) {
                $$ = $1->type;
            }
            else if ($1 == nulltype) {
                $$ = nulltype;
            }
            else {
                $$ = NULL;
            }

            /* code generation */
            // this code is for prevent from such as const_int fetch
            // fetch only "unary->ID" reduce case. (same condition!)
            if ((check_is_var($1) || check_is_array($1->type)) && !no_fetch) {
                CODE("fetch");
            }
            no_fetch = 0; // reset
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

            /* code generation */
            if (!is_array_decl)
                printf("\tpush_const %d\n", $$->value);
        }
        | CHAR_CONST
        {   
            $$ = makeintconstdecl(chartype, $1);

            /* code generation */
            printf("\tpush_const %d\n", $$->value);
        }
        | STRING
        {
            $$ = makestringconstdecl(stringtype, $1);

            /* code generation */
            printf("str_%d. string %s\n", new_string(), $$->stringvalue);
            printf("\tpush_const str_%d\n", stringnumber);
        }
        | ID {
            /* find ID */
            $$ = findcurrentdecl($1);
            if (!$$)
                ERROR("not declared");

            /* code generation */
            push_address($$);
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

            /* code generation */
            CODE("negate");
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

            /* code generation */
            CODE("not");
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

            /* code generation */
            CODE("fetch"); /* fetch! */
            push_address($$);
            push_address($$);
            CODE("fetch");
            CODE("push_const 1");
            CODE("add");
            CODE("assign");
            no_fetch = 1; /* it has already fetched */
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

            /* code generation */
            CODE("fetch"); /* fetch! */
            push_address($$);
            push_address($$);
            CODE("fetch");
            CODE("push_const -1");
            CODE("add");
            CODE("assign");
            no_fetch = 1; /* it has already fetched */
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

            /* code generation */
            // array access
            printf("\tpush_const %d\n", ($1->size)/($1->num_index));
            CODE("mul");
            CODE("add");
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

            /* code generation */
            // struct access
            printf("\tpush_const %d\n", $$->offset);
            CODE("add");
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
        | unary '(' codegen args ')'
        {
            /*
                function call!
                args pointer last pushed args.
                args->elementvar field pointer first pushed args.
            */

            if (check_is_proc($1)) {
                if ($4)
                    $$ = check_function_call($1, $4->elementvar);
            }
            else
                ERROR ("not a function");

            /* code generation */
            if ($1 == write_int) {
                CODE("write_int");
            }
            else if ($1 == write_string) {
                CODE("write_string");
            }
            else if ($1 == write_char) {
                CODE("write_char");
            }
            else {
                // push the actual parameters on the stack in 'args' reducing procedure
                CODE("push_reg sp"); // FP = SP
                printf("\tpush_const -%d\n", sumofargs);
                CODE("add");
                CODE("pop_reg fp");
                printf("\tjump %s\n", $1->id->name); // Then, jump
                printf("label_%d:\n", use_label()); // print label
                break;
            }
        }
        | unary '(' codegen ')'
        {
            if (check_is_proc($1)) 
                $$ = check_function_call($1, NULL);
            else
                ERROR ("not a function");

            /* code generation */
            // caller convention
            // no actual parameters
            CODE("push_reg sp"); // FP = SP
            CODE("pop_reg fp");
            printf("\tjump %s\n", $1->id->name); // Then, jump
        }
        | NULL_TOKEN
        {
            $$ = nulltype;
        }

codegen : /* empty */
        {
            /* code generation */
            // caller convention
            if($<declptr>-1 != write_int && $<declptr>-1 != write_string && $<declptr>-1 != write_char) {
                CODE("shift_sp 1"); // push a hole for return value
                printf("\tpush_const label_%d\n", new_label()); // push the return address
                CODE("push_reg fp"); // push the old FP
            }
            sumofargs = 0; // reset
        }

args    /* actual parameters(function arguments) transferred to function */
        : expr
        {
            /* expr semantic value type is TYPEDECL */
            $$ = makeconstdecl($1);
            $$->elementvar = $$; /* to save first args pointer. */

            /* code generation */
            sumofargs += $1->size; // set global variable for caller convention
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

            /* code generation */
            sumofargs += $1->size; // set global variable for caller convention
        }

%%

/*  Additional C Codes  */

int yyerror (char* s) {
    fprintf (stderr, "%s\n", s);
}

void push_address(struct decl* decl_ptr) {
    if (check_is_var(decl_ptr) || check_is_array(decl_ptr->type)) {
        switch (check_variable_scope(decl_ptr)) {
            case GLOBAL:
                CODE("push_const Lglob");
                printf("\tpush_const %d\n", decl_ptr->offset);
                CODE("add");
                break;

            case PARAM:
                CODE("push_reg fp");
                printf("\tpush_const %d\n", 1 + decl_ptr->offset);
                CODE("add");
                break;

            case LOCAL:
                CODE("push_reg fp");
                printf("\tpush_const %d\n", 1 + decl_ptr->scope->sumofparams + decl_ptr->offset);
                CODE("add");
                break;

            default:
                break;
        }
    }
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

int new_label() {
    return ++unused_labelnumber;
}

int use_label() {
    if (used_labelnumber < unused_labelnumber)
        return ++used_labelnumber;
    else {
        printf("* * LABELING ERROR!!!!!\n");
        return -1;
    }
}

int new_string() {
    return ++stringnumber;
}