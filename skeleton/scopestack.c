/***************************************************************
 * File Name    : scopestack.c
 * Description
 *      This is an implementation file for dynamic scope stack
 *
 ****************************************************************/

#include "subc.h"

void printscopestack(){
  if (debugging) {
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
            printf ("node name : %s, decl class : %d, size : %d, offset : %d, scope : %d, check_param : %d\n", ste_it->name->name, ste_it->decl->declclass, ste_it->decl->size, ste_it->decl->offset, *(ste_it->decl->scope) == globalscope->data, ste_it->decl->check_param);
          ste_it = ste_it->prev;
        }
        node_it = node_it->next;
      }

      printf("=====Final Stack from the top=====\n");
      while (ste_it != NULL) {
        if(ste_it->name == NULL || ste_it->decl == NULL)
            printf("ste_it->name == NULL || ste_it->decl == NULL\n");
          else
            printf ("node name : %s, decl class : %d, size : %d, offset : %d, scope : %d, check_param : %d\n", ste_it->name->name, ste_it->decl->declclass, ste_it->decl->size, ste_it->decl->offset, *(ste_it->decl->scope) == globalscope->data, ste_it->decl->check_param);      ste_it = ste_it->prev;
      }
    }
    printf("===========================================\n");
  }
}

struct ste *insert(struct id* id_ptr, struct decl* decl_ptr) {
  if (top != NULL) {
    // Declare new ste & initialization
    struct ste *ste_ptr = malloc(sizeof(struct ste));
    ste_ptr->name = id_ptr;
    ste_ptr->decl = decl_ptr;
    ste_ptr->decl->offset = top->sumofsize; // set offset
    ste_ptr->decl->scope = &(top->data); // set scope
    ste_ptr->decl->id = id_ptr; // set id
    ste_ptr->prev = top->data; // The first ste of the first scope's prev is NULL

    // Set the top->data of the scope stack
    top->data = ste_ptr;

    // Update the sumofsize (if this is not in formalswithreturnid)
    if (id_ptr != returnid)
      top->sumofsize += ste_ptr->decl->size;

    return ste_ptr;
  } else {
    return NULL;
  }
}

void insert_bottom(struct id* id_ptr, struct decl* decl_ptr) {
  /* for insert struct to global scope */
  if (top != NULL) {
    // Declare new ste & initialization
    struct ste *ste_ptr = malloc(sizeof(struct ste));
    ste_ptr->name = id_ptr;
    ste_ptr->decl = decl_ptr;
    ste_ptr->decl->offset = bottom->sumofsize; // set offset
    ste_ptr->decl->scope = &(bottom->data); // set scope
    ste_ptr->decl->id = id_ptr; // set id
    ste_ptr->prev = NULL; // The first ste of the first scope's prev is NULL
    bottom_ste->prev = ste_ptr;

    // Set the bottom of the scope stack
    bottom_ste = ste_ptr;

    // Update the sumofsize
    bottom->sumofsize += ste_ptr->decl->size;
  } else {
    //printf("Scope stack top is NULL!\n");
  }
}

struct ste *lookup(struct id* id_ptr) {
  /*
    Return ste linked list having same id_ptr in GLOBAL SCOPE
    If not, return NULL
  */
  // [TODO] This malloc has temporary objective. memory leak..
  struct ste *ste_list = malloc(sizeof(struct ste));
  struct ste *ste_list_result = ste_list;

  if (top != NULL) {
    struct ste *ste_it = top->data;
    while (ste_it != NULL) {
      // make list of same id decl until stack end
      if (ste_it->name == id_ptr) {
        ste_list->name = ste_it->name;
        ste_list->decl = ste_it->decl;
        // [TODO] memory leak
        struct ste *new_ste_list = malloc(sizeof(struct ste));
        ste_list->prev = new_ste_list;
        ste_list = ste_list->prev;
      }
      ste_it = ste_it->prev;
    }
    ste_list = NULL;
    if (!ste_list_result->name)
      return NULL; // can not find
    return ste_list_result;
  } else {
    // Scope stack top is NULL
    return NULL;
  }
}

struct ste *lookup_local_scope(struct id* id_ptr, struct node* scope) {
  /*
    Return ste linked list having same id_ptr in LOCAL SCOPE
    If not, return NULL
  */

  // [TODO] This malloc has temporary objective. memory leak..
  struct ste *ste_list = malloc(sizeof(struct ste));
  struct ste *ste_list_result = ste_list;
  struct ste *ste_end_flag = NULL;

  if (scope != NULL) {
    if (scope->next)
      ste_end_flag = scope->next->data;

    struct ste *ste_it = scope->data;
    while (ste_it != ste_end_flag) {
      // make list of same id decl until stack end
      if (ste_it->name == id_ptr) {
        ste_list->name = ste_it->name;
        ste_list->decl = ste_it->decl;
        // [TODO] memory leak
        struct ste *new_ste_list = malloc(sizeof(struct ste));
        ste_list->prev = new_ste_list;
        ste_list = ste_list->prev;
      }
      ste_it = ste_it->prev;
    }
    ste_list = NULL;

    if (!ste_list_result->name) {
      // [TODO] memory leak
      ste_list_result = NULL;
    }
    return ste_list_result;
  } else {
    // Local scope stack is NULL!
    return NULL;
  }
}

struct node *pushscope() {
  // Declare new scope node & initialization
  struct node *node_ptr = malloc(sizeof(struct node));
  if (top != NULL)
    node_ptr->data = top->data;
  else
    node_ptr->data = NULL; // This is tje first node
  node_ptr->next = top; // The first node's next is NULL

  // Set the top of the scope stack
  top = node_ptr;

  return node_ptr;
}

void pushstelist(ste *ste_list) {
  struct ste *ste_it = ste_list;
  int sum_of_param_size = 0;

  // set sum_of_param_size
  while (ste_it != NULL) {
    if (ste_it->name != returnid)
      sum_of_param_size += ste_it->decl->size;
    ste_it = ste_it->prev;
  }

  // set check_param & insert
  ste_it = ste_list;
  while (ste_it != NULL) {
    if (ste_it->name != returnid)
      ste_it->decl->check_param = sum_of_param_size;
    insert(ste_it->name, ste_it->decl); // malloc
    ste_it = ste_it->prev;
  }
}

struct ste *popscope() {
  /*
    return a ste linked list of stack top scope.
    *REVERSE ORDER*
  */

  // [TODO] memory leak..
  if (top == NULL) {
    // Scope stack is NULL
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
  if (top == NULL || top->data == NULL) {
    // Scope stack top node or ste is NULL
    return NULL;
  } else {
    struct ste *top_ste = top->data;
    top->data = top->data->prev;
    top_ste->prev = NULL;
    return top_ste;
  }
}