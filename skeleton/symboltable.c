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

struct decl *makestructdecl(struct ste* fields) {
	printf("makestructdecl()\n");

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = STRUCT_;
	new_decl->fieldlist = fields;

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
	struct ste* result = lookup(id_ptr);
	if (result == NULL)
		return NULL;
	else return result->decl;
}

struct decl *find_decl_in_struct_fields(struct id* field_id, struct ste* fieldlist) {
	while (fieldlist != NULL) {
		if (fieldlist->name == field_id)
			return fieldlist->decl;
		else
			fieldlist = fieldlist->prev;
	}

	printf ("ERROR : there is no such field name in this struct!\n");
	return NULL;
}

struct decl *arrayaccess(struct decl* array_ptr, struct decl* index_ptr) {
	/* 38p definition!! */
	struct decl *arraytype = array_ptr->type;
	if (check_is_array(arraytype)) {
		printf("this is array!\n");
		if (check_same_type(inttype, index_ptr))
			return (arraytype->elementvar);
		else {
			printf("ERROR : array index is not int type.\n");
		}
	}
	else {
		printf("ERROR : this is not array type.\n");
	}
	return NULL;
}

struct decl *structaccess(struct decl* struct_ptr, struct id* field_id) {
	/* 38p definition!! */
	struct decl *type_ptr = struct_ptr->type;
	if (check_is_struct_type(type_ptr))
		return (find_decl_in_struct_fields(field_id, type_ptr->fieldlist));
	else
		printf("ERROR : This is not struct type!\n");
	return NULL;
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
	if (decl_ptr != NULL && decl_ptr->declclass == TYPE_ && decl_ptr->typeclass == STRUCT_)
		return 1;
	else return 0;
}

int check_is_var(decl* decl_ptr) {
	// 37p
	// return 0 or 1. (true or false)
	if (decl_ptr != NULL && decl_ptr->declclass == VAR_)
		return 1;
	else return 0;
}

int check_is_array(decl* decl_ptr) {
	// 38p
	// return 0 or 1. (true or false)
	if (decl_ptr != NULL && decl_ptr->declclass == TYPE_ && decl_ptr->typeclass == ARRAY_)
		return 1;
	else return 0;
}

int check_is_proc(decl* decl_ptr) {
	// 39p
	// return 0 or 1. (true or false)
	if (decl_ptr != NULL && decl_ptr->declclass == FUNC_)
		return 1;
	else return 0;
}

struct decl* check_function_call(decl* proc_ptr, decl* actuals) {
	// 40p definition!!!
	struct ste *formals = proc_ptr->formals;

	/*
		1. compare the num of formals and actuals.
		2. and check for type match
	*/

	while (formals != NULL && actuals != NULL) {
		if (check_is_var(formals->decl->type) && check_compatible(formals->decl, actuals)) {
			formals = formals->prev;
			actuals = actuals->next;
		}
		else {
			printf("ERROR : formals, actuals type is not compatible.\n");
			return NULL;
		}
	}

	// num of actuals, formals check
	if (formals == NULL && actuals == NULL) {
		// same number of formals, actuals
		// [TODO] I'm not sure const decl is right type.
  	return makeconstdecl(proc_ptr->returntype);
	}
	else {
  	// different number of formals, actuals
  	printf ("ERROR : different number of formals, actuals\n");
  	return NULL;
	}
}

int check_compatible(decl* decl_ptr, decl* typedecl_ptr) {
	// 37p, 39p
	// return 0 or 1. (true or false)
	if (decl_ptr->type == typedecl_ptr)
		return 1;
	else return 0;
}

int check_same_type(decl* typedecl_ptr1, decl* typedecl_ptr2) {
	// 36p, 38p
	if (typedecl_ptr1 == typedecl_ptr2)
		return 1;
	else return 0;
}



///////////////////////////////////////
////// print declaration function /////
///////////////////////////////////////

void init_type()
{
	printf("==init_type() START==\n");

	inttype = maketypedecl(INT_);
	chartype = maketypedecl(CHAR_);
	voidtype = maketypedecl(VOID_);
	stringtype = maketypedecl(STRING_);

	pushscope();
	declare(enter(KEYWORD, "int", 3), inttype);
	declare(enter(KEYWORD, "char", 4), chartype);
	declare(enter(KEYWORD, "void", 4), voidtype);
	declare(enter(KEYWORD, "string", 6), stringtype);

	returnid = enter(KEYWORD, "*return", 7);

	printf("==init_type() END==\n");
}

void printTypeDecl(struct decl* decl_ptr) {
    printf("--Print Type Decl--\n");
    printf("* declclass = %d\n", decl_ptr->declclass);
    printf("* typeclass = %d\n", decl_ptr->typeclass);
    printf("-------------------\n");
}