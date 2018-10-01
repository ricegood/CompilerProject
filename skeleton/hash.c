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

    ////////////////////
    /* find the token */
    ////////////////////

    // hash function : (length) % HASH_TABLE_SIZE
    struct nlist* node;
    int key = (length) % HASH_TABLE_SIZE;
    printf("key of %s : %d\n", name, key);
    // allocation pointer to node
    node = hashTable[key];

    // while node is not null
    while (node) {
        // check existence
        // Q. Should I check (node->data->tokenType == tokenType) ?????
        if (strcmp(node->data->name,name) == 0) {
            node->data->count++;
            return node->data;
        }
        node = node->next;
    }



    ///////////////
    /* ADD TOKEN */
    ///////////////

    // memory allocation to temp_id
    struct id* temp_id = malloc(sizeof(struct id));
    temp_id->tokenType = tokenType;
    temp_id->name = name;
    temp_id->count = 0;

    // if token type is undefined, it must be ID.
    if (tokenType == UNDEFINED) {
        temp_id->tokenType = ID;
        temp_id->count = 1;
    }

    // memory allocation to temp_nlist
    struct nlist* temp_nlist = malloc(sizeof(struct nlist));
    temp_nlist->next = NULL;
    temp_nlist->data = temp_id;

    // add to hash table
    hashTable[key] = temp_nlist;

    printf("hash entered!\n");
    return temp_nlist->data;
}