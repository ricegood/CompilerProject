/***************************************************************
 * File Name    : scopestack.c
 * Description
 *      This is an implementation file for dynamic scope stack
 *
 ****************************************************************/

#include "subc.h"

static struct node *top = NULL;

void printscopestack(){
  printf("=============PRINT SCOPE STACK=============\n");
  struct node *node_it = top;
  struct ste *ste_it = NULL;

  if (node_it == NULL)
    printf("stack is NULL!\n");
  else {
    ste_it = node_it->data;

    int i = 0;
    while (node_it->next != NULL) {
      printf("=====stack #%d from the top=====\n", i++);
      while (ste_it != node_it->next->data) {
        if(ste_it->name == NULL || ste_it->decl == NULL)
          printf("ste_it->name == NULL || ste_it->decl == NULL\n");
        else
          printf ("node name : %s, decl class : %d\n", ste_it->name->name, ste_it->decl->declclass);
        ste_it = ste_it->prev;
      }
      node_it = node_it->next;
    }

    printf("=====Final Stack from the top=====\n");
    while (ste_it != NULL) {
      if(ste_it->name == NULL || ste_it->decl == NULL)
          printf("ste_it->name == NULL || ste_it->decl == NULL\n");
        else
          printf ("node name : %s, decl class : %d\n", ste_it->name->name, ste_it->decl->declclass);
      ste_it = ste_it->prev;
    }
  }
  printf("===========================================\n");
}

void insert(struct id* id_ptr, struct decl* decl_ptr) {
  printf("insert ste to scope stack!\n");
  if (top != NULL) {
    // Declare new ste & initialization
    struct ste *ste_ptr = malloc(sizeof(struct ste));
    ste_ptr->name = id_ptr;
    ste_ptr->decl = decl_ptr;
    ste_ptr->prev = top->data; // The first ste of the first scope's prev is NULL

    // Set the top->data of the scope stack
    top->data = ste_ptr;
  } else {
    printf("Scope stack top is NULL!\n");
  }
}

struct ste *lookup(struct id* id_ptr) {
  /*
    Return last pushed ste having same id_ptr
    If not, return NULL
  */

  if (top != NULL) {
    struct ste *ste_it = top->data;
    while (ste_it != NULL) {
      if (ste_it->name == id_ptr) return ste_it;
      else ste_it = ste_it->prev;
    }
    return NULL;
  } else {
    printf("Scope stack top is NULL!\n");
    return NULL;
  }
}

void pushscope() {
  printf("push scope\n");
  // Declare new scope node & initialization
  struct node *node_ptr = malloc(sizeof(struct node));
  if (top != NULL)
    node_ptr->data = top->data;
  else
    node_ptr->data = NULL; // This is tje first node
  node_ptr->next = top; // The first node's next is NULL

  // Set the top of the scope stack
  top = node_ptr;
}

void pushstelist(ste *ste_list) {
  /* Should I do malloc? or it's jusk OK to link the pointer??.. */
  struct ste *ste_it = ste_list;
  while (ste_it != NULL) {
    insert(ste_it->name, ste_it->decl);
    ste_it = ste_it->prev;
  }
}

struct ste *popscope() {
  printf("pop scope\n");
  /*
    return a ste linked list of stack top scope.
    *REVERSE ORDER*
  */

  // [TODO] memory leak..
  
  if (top == NULL) {
    printf("Scope stack is NULL!\n");
    return NULL;
  } else {
    // get a pointer of next scope top ste.
    struct ste *next_top_ste = NULL;
    if (top->next != NULL)
      next_top_ste = top->next->data;

    // make 'top_node_ste_list' with reverse order
    struct ste *top_node_ste_list = NULL;
    while (top->data != next_top_ste) {
      struct ste *temp_ste = top_node_ste_list;
      top_node_ste_list = popste();
      top_node_ste_list->prev = temp_ste;
    }

    // change the pointer of top & free the top node
    struct node *temp_top = top;
    top = top->next;
    free(temp_top);

    return top_node_ste_list;
  }
}

struct ste *popste() {
  printf("pop ste\n");
  if (top == NULL || top->data == NULL) {
    printf("Scope stack top node or ste is NULL!\n");
    return NULL;
  } else {
    struct ste *top_ste = top->data;
    top->data = top->data->prev;
    top_ste->prev = NULL;
    return top_ste;
  }
}