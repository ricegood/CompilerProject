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

void print(nlist* table[HASH_TABLE_SIZE]) {
    // print hash table
        struct nlist* n;
        printf("==================================\n");
        for(int i=0; i<HASH_TABLE_SIZE; i++) {
            n = table[i];
            while(n){
                printf("%s\t(%p)\n",n->data->name,n->data->name);
                n = n->next;
            }
        }
        printf("==================================\n");
}

id *enter(int tokenType, char *name, int length) {
    
    ////////////////////
    /* find the token */
    ////////////////////

    // hash function : (length) % HASH_TABLE_SIZE
    struct nlist* node;
    int key = (length) % HASH_TABLE_SIZE;

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
        if(node->next)
            node = node->next;
        else break;
    }



    ///////////////
    /* ADD TOKEN */
    ///////////////

    // memory allocation to temp_id
    struct id* temp_id = malloc(sizeof(struct id));
    char* temp_name = malloc(sizeof(name)); // due to yytext is pointer so value is changable.
    strcpy(temp_name, name);
    temp_id->tokenType = tokenType;
    temp_id->name = temp_name;
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
    if (node){
        node->next = temp_nlist;
    }
    else{
        hashTable[key] = temp_nlist;
    }

    return temp_nlist->data;
}