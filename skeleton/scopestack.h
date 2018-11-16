/******************************************************
 * File Name   : scopestack.h
 * Description
 *    This is a header file for the scopestack.
 ******************************************************/

#include "subc.h"

typedef struct node
{
    struct ste *data;
    struct node *next;
} node;

static struct node *top = NULL;

void insert(struct id* id_ptr, struct decl* decl_ptr);
struct ste *lookup(){struct id* id_ptr}; // return last pushed element
void pushscope();
void pushstelist(ste *ste_list);
struct ste *popscope();
struct ste *popste();