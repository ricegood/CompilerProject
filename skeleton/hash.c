/***************************************************************
 * File Name    : hash.c
 * Description
 *      This is an implementation file for the open hash table.
 *
 ****************************************************************/

#include "subc.h"

#define  HASH_TABLE_SIZE   101

typedef struct nlist {
	struct nlist *next;
	id *data;
} nlist;

static nlist *hashTable[HASH_TABLE_SIZE];

id *enter(int tokenType, char *name, int length) {
    /* implementation is given here */
  
    // hash function : (tokenType + length) % HASH_TABLE_SIZE
    struct nlist* node;
    int key = (tokenType + length) % HASH_TABLE_SIZE;

    // allocation pointer to node
    node = hashTable[key];

    // memory allocation
    struct id* temp_id = malloc(sizeof(struct id));
    temp_id->tokenType = tokenType;
    temp_id->name = name;
    temp_id->count = 0;

    struct nlist* temp_nlist = malloc(sizeof(struct nlist));
    temp_nlist->next = NULL;
    temp_nlist->data = temp_id;

    // insert to NULL node
    if (node) {
      while (node->next) {
        node = node->next;
      }
      node->next = temp_nlist;
    }
    else hashTable[key] = temp_nlist;

    return temp_id;
}