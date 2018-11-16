/***************************************************************
 * File Name    : symboltable.c
 * Description
 *      This is an implementation file for symbol table
 *
 ****************************************************************/

#include "subc.h"

struct decl *maketypedecl(int typeclass) {
	printf("maketypedecl()\n");
	switch (typeclass) {
		case INT_:
					break;
		case CHAR_:
					break;
		case VOID_:
					break;
		case STRUCT_:
					break;
		case STRING_:
					break;
		case ARRAY_:
					break;
		case POINTER_:
					break;
		default: ;
	}
}

struct decl *makevardecl(struct decl* typedecl) {

}

struct decl *makearraydecl(int size, struct decl* vardecl) {
	// I think array type is in the vardecl's type field.
}

struct decl *makeconstdecl(struct decl* typedecl) {

}

struct decl *makenumconstdecl(struct decl* typedecl, int value) {
	// 37p
	// use typedecl = inttype default... how can I do this ????
	// firstly... How can I access to inttype ??
	// oh... maybe findcurrentdecl(lookup("int")) !
}

struct decl *makeptrdecl(struct decl* typedecl) {

}

struct decl *makeprocdecl() {

}

struct decl *findcurrentdecl(struct id* id_ptr) {

}

struct decl *arrayaccess(struct decl* array_ptr, struct decl* index_ptr) {
	/* 38p definition!! */
}

struct decl *structaccess(struct decl* struct_ptr, struct id* field_id) {
	/* 38p definition!! */
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

struct ste *makeste() {

}

/* Make ste and add to ste stack linked list */
void declare(struct id* id_ptr, struct decl* decl_ptr) {
	printf("declare()\n");
	// make ste

	// add to ste stack linked list
}

void add_type_to_var(struct decl* typedecl, struct decl* var_list) {

}

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