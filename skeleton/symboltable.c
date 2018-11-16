/***************************************************************
 * File Name    : symboltable.c
 * Description
 *      This is an implementation file for symbol table
 *
 ****************************************************************/

#include "subc.h"


/* Make ste and add to symbol table (ste stack linked list) */
void declare(struct id* id_ptr, struct decl* decl_ptr) {
	printf("declare()\n");
	
	// add to ste stack linked list
	insert(id_ptr, decl_ptr);
}



////////////////////////////////////
//////// make decl function ////////
////////////////////////////////////

struct decl *maketypedecl(int typeclass) {
	/*
		This function is only for init_type();
		int, char, void, string
	*/

	printf("maketypedecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = typeclass;

	return new_decl;
}

struct decl *makeptrdecl(struct decl* typedecl) {
	printf("makeptrdecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = POINTER_;
	new_decl->ptrto = typedecl;

	return new_decl;
}

struct decl *makearraydecl(int size, struct decl* vardecl) {
	printf("makearraydecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = ARRAY_;
	new_decl->elementvar = vardecl;
	new_decl->num_index = size;

	return new_decl;
}

struct decl *makestructdecl() {
	printf("makestructdecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = STRUCT_;

	return new_decl;
}

struct decl *makevardecl(struct decl* typedecl) {
	printf("makevardecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = VAR_;
	new_decl->type = typedecl;

	return new_decl;
}

struct decl *makeconstdecl(struct decl* typedecl) {
	printf("makeconstdecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = CONST_;
	new_decl->type = typedecl;
	// how about value??

	return new_decl;
}

struct decl *makeintconstdecl(struct decl* typedecl, int value) {
	// 37p
	// use typedecl = inttype default... how can I do this ????
	// firstly... How can I access to inttype ??
	// oh... maybe findcurrentdecl(lookup("int")) !
	printf("makeintconstdecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = CONST_;
	new_decl->type = typedecl;
	new_decl->value = value;

	return new_decl;
}

struct decl *makefloatconstdecl(struct decl* typedecl, float value) {
	// float version
	printf("makefloatconstdecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = CONST_;
	new_decl->type = typedecl;
	new_decl->real_value = value;

	return new_decl;
}

struct decl *makeprocdecl() {
	printf("makeprocdecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = FUNC_;

	return new_decl;
}



////////////////////////////////////
////// find & access function //////
////////////////////////////////////

struct decl *findcurrentdecl(struct id* id_ptr) {
	struct ste* result = lookup(id_ptr)->data;
	if (result == NULL)
		return NULL;
	else return result->data;
}

struct decl *arrayaccess(struct decl* array_ptr, struct decl* index_ptr) {
	/* 38p definition!! */
}

struct decl *structaccess(struct decl* struct_ptr, struct id* field_id) {
	/* 38p definition!! */
}

void add_type_to_var(struct decl* typedecl, struct decl* var_list) {

}

struct decl *plustype(struct decl typedecl1, struct decl typedecl2) {
	// 37p
	// 39p definition!!
	// no pointer in param..?
	/*
		I think 'minustype' and etc... are needed!!!
     binary     : binary RELOP binary
     				   | binary EQUOP binary
       				 | binary '+' binary
        			 | binary '-' binary
        			 | unary %prec '='

	*/
}




///////////////////////////////////////
////// check compatible function //////
///////////////////////////////////////

int check_is_type(decl* decl_ptr) {
	// return 0 or 1. (true or false)
}

int check_is_struct_type(decl* decl_ptr) {
	// return 0 or 1. (true or false)
}

int check_is_var(decl* decl_ptr) {
	// 37p
	// return 0 or 1. (true or false)
}

int check_is_array(decl* decl_ptr) {
	// 38p
	// return 0 or 1. (true or false)
}

int check_is_proc(decl* decl_ptr) {
	// 39p
	// return 0 or 1. (true or false)
}

struct decl* check_function_call(decl* proc_ptr, decl* actuals) {
	// 39p
	// 40p definition!!!
	// return 0 or 1. (true or false)
}

int check_compatible(decl* decl_ptr, decl* typedecl_ptr) {
	// 37p, 39p
	// return 0 or 1. (true or false)
}

int check_same_type(decl* decl_ptr, decl* indexptr) {
	// 38p
	// decl_ptr = inttype. how?
	// return 0 or 1. (true or false)
}