/***************************************************************
 * File Name    : symboltable.c
 * Description
 *      This is an implementation file for symbol table
 *
 ****************************************************************/

#include "subc.h"

/* Make ste and add to symbol table (ste stack linked list) */
int declare(struct id* id_ptr, struct decl* decl_ptr) {
	/* return error_found */
	if (!id_ptr) {
		// declare failed. id_ptr or decl_ptr is null
		printscopestack();
		return 1;
	}

	else if (check_redeclaration(id_ptr, decl_ptr)) {
		ERROR("redeclaration");
		printscopestack();
		return 1;
		// [TODO] memory leak
	}

	else{
		// add to ste stack linked list
		if (!(id_ptr == returnid) && check_is_struct_type(decl_ptr)) {
			// add to bottom for local scope struct
			insert_bottom(id_ptr, decl_ptr);
		}
		else {
			// add to top
			insert(id_ptr, decl_ptr);
		}
		printscopestack();
		return 0;
	}
}


////////////////////////////////////
//////// make decl function ////////
////////////////////////////////////

struct decl *maketypedecl(int typeclass) {
	/*
		This function is only for init_type();
		int, char, void, string
		+ NULL decl
	*/

	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = typeclass;
	new_decl->size = WORD_SIZE;

	return new_decl;
}

struct decl *makeptrdecl(struct decl* typedecl) {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = POINTER_;
	new_decl->ptrto = typedecl;
	new_decl->size = WORD_SIZE;

	return new_decl;
}

struct decl *makearraydecl(int size, struct decl* vardecl) {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = ARRAY_;
	new_decl->elementvar = vardecl;
	new_decl->num_index = size;
	new_decl->size = vardecl->size * size;

	return new_decl;
}

struct decl *makestructdecl(struct ste* fields) {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));
	struct ste *fields_ptr = fields;

	/* initialization */
	new_decl->declclass = TYPE_;
	new_decl->typeclass = STRUCT_;
	new_decl->fieldlist = fields;

	/* set size */
	while (fields) {
		new_decl->size += fields->decl->size;
		fields = fields->prev;
	}

	return new_decl;
}

struct decl *makevardecl(struct decl* typedecl) {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = VAR_;
	new_decl->type = typedecl;
	new_decl->size = typedecl->size;

	return new_decl;
}

struct decl *makeconstdecl(struct decl* typedecl) {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = CONST_;
	new_decl->type = typedecl;
	new_decl->size = typedecl->size;

	return new_decl;
}

struct decl *makeintconstdecl(struct decl* typedecl, int value) {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = CONST_;
	new_decl->type = typedecl;
	new_decl->value = value;
	new_decl->size = typedecl->size;

	return new_decl;
}

struct decl *makefloatconstdecl(struct decl* typedecl, float value) {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = CONST_;
	new_decl->type = typedecl;
	new_decl->real_value = value;
	new_decl->size = typedecl->size;

	return new_decl;
}

struct decl *makeprocdecl() {
	/* make new decl */
	struct decl *new_decl = malloc(sizeof(struct decl));

	/* initialization */
	new_decl->declclass = FUNC_;

	return new_decl;
}


///////////////////////////////////////
////// check compatible function //////
///////////////////////////////////////

int check_is_struct_type(decl* decl_ptr) {
	// return 0 or 1. (true or false)
	if (decl_ptr != NULL && decl_ptr->declclass == TYPE_ && decl_ptr->typeclass == STRUCT_)
		return 1;
	else return 0;
}

int check_is_pointer_type(decl* decl_ptr) {
	if (decl_ptr != NULL && decl_ptr->declclass == TYPE_ && decl_ptr->typeclass == POINTER_)
		return 1;
	else return 0;
}

int check_is_var(decl* decl_ptr) {
	// return 0 or 1. (true or false)
	if (decl_ptr != NULL && decl_ptr->declclass == VAR_)
		return 1;
	else {
		return 0;
	}
}

int check_is_array(decl* decl_ptr) {
	// return 0 or 1. (true or false)
	if (decl_ptr != NULL && decl_ptr->declclass == TYPE_ && decl_ptr->typeclass == ARRAY_)
		return 1;
	else return 0;
}

int check_is_proc(decl* decl_ptr) {
	// return 0 or 1. (true or false)
	if (decl_ptr != NULL && decl_ptr->declclass == FUNC_)
		return 1;
	else return 0;
}

struct decl* check_function_call(decl* proc_ptr, decl* actuals) {
	struct ste *formals = proc_ptr->formals;

	/*
		1. compare the num of formals and actuals.
		2. and check for type match
		* actuals = const decl (const is not important. it is just temporal decl to save type field and next ptr.)
	*/

	while (formals != NULL && formals->decl != NULL && actuals != NULL && actuals->type != NULL) {
		if (check_is_var(formals->decl) && check_same_type(formals->decl->type, actuals->type)) {
			formals = formals->prev;
			// [TODO] save this actual pointer to delete
			actuals = actuals->next;
			// [TODO] memory leak
		}
		else {
			ERROR("actual args are not equal to formal args");
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
  	ERROR("actual args are not equal to formal args");
  	return NULL;
	}
}

int check_same_type_for_unary(decl* decl_ptr, decl* typedecl_ptr) {
	if (!decl_ptr) {
		// decl_ptr is NULL, so can't check the type
	}
	else
		return check_same_type(decl_ptr->type, typedecl_ptr);
}

int check_same_type(decl* typedecl_ptr1, decl* typedecl_ptr2) {
	if (typedecl_ptr1 == typedecl_ptr2){
		return 1;
	}

	// if Lvalue is pointer type, have to check ptrto of Rvalue, OR NULL
	else if (check_is_pointer_type(typedecl_ptr1)){
		if (check_is_pointer_type(typedecl_ptr2) && typedecl_ptr1->ptrto == typedecl_ptr2->ptrto)
			return 1;
		else if (typedecl_ptr2 == nulltype)
			return 1;
		else if (typedecl_ptr1->ptrto == chartype && typedecl_ptr2 == stringtype)
			return 1;
	}

	// not the same type
	return 0;
}

int check_same_decl(decl* decl_ptr1, decl* decl_ptr2) {
	if (decl_ptr1 && decl_ptr2) {
		if (decl_ptr1->declclass == decl_ptr2->declclass) {
			return 1;
		}
	}
	return 0;
}

struct decl *check_compatible_type(decl* typedecl_ptr1, decl* typedecl_ptr2) {
	if (typedecl_ptr1 == typedecl_ptr2)
		return typedecl_ptr1;
	else {
		return NULL;
	}
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

struct ste *findcurrentdecls(struct id* id_ptr) {
	struct ste* result = lookup(id_ptr);
	return result;
}

struct ste *findcurrentdecls_local(struct id* id_ptr) {
	struct ste* result = lookup_local_scope(id_ptr, top);
	return result;
}

struct decl *findstructdecl(struct id* id_ptr) {
	struct ste* result = lookup_local_scope(id_ptr, bottom);
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

	ERROR("struct not have same name field");
	return NULL;
}

struct decl *arrayaccess(struct decl* array_ptr, struct decl* index_ptr) {
	/* 38p definition */
	struct decl *arraytype = array_ptr->type;
	if (check_is_array(arraytype)) {
		if (check_same_type(inttype, index_ptr))
			return (arraytype->elementvar);
		else {
			// array index is not int type
			ERROR("not int type");
		}
	}
	else {
		ERROR("not array type");
	}
	return NULL;
}

struct decl *structaccess(struct decl* struct_ptr, struct id* field_id) {
	/* 38p definition */
	if (!struct_ptr){
		return NULL;
	}
	struct decl *type_ptr;
	if (check_is_pointer_type(struct_ptr->type))
		type_ptr = struct_ptr->type->ptrto;
	else
		type_ptr = struct_ptr->type;

	if (check_is_struct_type(type_ptr))
		return (find_decl_in_struct_fields(field_id, type_ptr->fieldlist));
	else
		ERROR("variable is not struct");
	return NULL;
}

void add_type_to_var(struct decl* typedecl, struct decl* var_list) {

}

int check_redeclaration(struct id* id_ptr, struct decl* decl_ptr) {
	/*
		check redeclaration in LOCAL SCOPE (** structure : global scope).
		if redeclaration, return 1
		else, initial declaration, return 0
	*/

	if (id_ptr == returnid) {
		// returnid redeclaration is OK
		return 0;
	}

	// struct type = find in global scope
	else if (check_is_struct_type(decl_ptr)) {
		struct ste *same_id_ste_list = findcurrentdecls(id_ptr);
		while (same_id_ste_list) {
			if (check_is_struct_type(same_id_ste_list->decl)) {
				return 1;
			}
			else
				same_id_ste_list = same_id_ste_list->prev;
		}
		return 0;
	}

	/* [non struct type (else case)]
			procdecl
			vardecl(type)
			vardecl(ptrdecl(type))
			constdecl(arraydecl(size, vardecl(type)))

			so, decl type = proc | var | const
	*/

	// else case = find in local scope
	else {
		struct ste *same_id_ste_list = findcurrentdecls_local(id_ptr);
		if (same_id_ste_list) {
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

struct decl *plustype(struct decl* typedecl1, struct decl* typedecl2) {
	struct decl *type_after;
	type_after = check_compatible_type(typedecl1, typedecl2);
	return type_after;
}


///////////////////////////////////////
////// print declaration function /////
///////////////////////////////////////

void init_type()
{
	top = NULL;
	bottom = NULL;

	inttype = maketypedecl(INT_);
	chartype = maketypedecl(CHAR_);
	voidtype = maketypedecl(VOID_);
	stringtype = maketypedecl(STRING_);
	nulltype = maketypedecl(POINTER_);

	bottom = pushscope();

	bottom_ste = insert(enter(KEYWORD, "int", 3), inttype); // set bottom ste
	inttype_ste = bottom_ste; // fixed inttype ste pointer
	insert(enter(KEYWORD, "char", 4), chartype);
	insert(enter(KEYWORD, "void", 4), voidtype);
	insert(enter(KEYWORD, "string", 6), stringtype);

	returnid = enter(KEYWORD, "*return", 7);

	globalscope = pushscope();

	CODE("shift_sp 1");
	CODE("push_const EXIT");
	CODE("push_reg fp");
	CODE("push_reg sp");
	CODE("pop_reg fp");
	CODE("jump main");
	LABEL("EXIT");
	CODE("exit");
	LABEL("main");
}

void printTypeDecl(struct decl* decl_ptr) {
    printf("--Print Type Decl--\n");
    printf("* declclass = %d\n", decl_ptr->declclass);
    printf("* typeclass = %d\n", decl_ptr->typeclass);
    printf("-------------------\n");
}

void printArgs(struct decl* const_decl_for_args) {
	printf("--Print Args--\n");
	int i = 1;
    while (const_decl_for_args) {
    	printf("args [%d] type : %d\n", i++, const_decl_for_args->type->typeclass);
    	const_decl_for_args = const_decl_for_args->next;
    }
    printf("-------------------\n");
}