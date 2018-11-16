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
    struct id *data;
} nlist;

static struct nlist *hashTable[HASH_TABLE_SIZE];

/* Print the Hash Table */
void print(nlist* table[HASH_TABLE_SIZE]) {
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

unsigned hash(char *name) {
   /* implementation is given here */
}

/* Enter token to Hash Table */
struct id *enter(int lexType, char *name, int length) {
    
    ////////////////
    /* FIND TOKEN */
    ////////////////

    // Hash Function : ((first char ascii code)*(length)) % HASH_TABLE_SIZE
    struct nlist* node;
    int key = ((*name) * (length)) % HASH_TABLE_SIZE;

    // Allocation pointer to node
    node = hashTable[key];

    // While node is not NULL
    while (node) {
        // Check existence
        if (strcmp(node->data->name,name) == 0) {
            node->data->count++;
            // If the token exists, return the data
            return node->data;
        }
        if(node->next)
            node = node->next;
        else break;
    }


    // If the token doesn't exist, add the token.

    ///////////////
    /* ADD TOKEN */
    ///////////////

    // Memory allocation for temp_id
    struct id* temp_id = malloc(sizeof(struct id));
    char* temp_name = malloc(length+1); // due to yytext is pointer so value is changable.
    strcpy(temp_name, name);
    temp_id->lexType = lexType;
    temp_id->name = temp_name;
    temp_id->count = 0;

    // If the token type is UNDEFINED, It must be ID.
    if (lexType == UNDEFINED) {
        temp_id->lexType = ID_;
        temp_id->count = 1;
    }

    // Memory allocation for temp_nlist
    struct nlist* temp_nlist = malloc(sizeof(struct nlist));
    temp_nlist->next = NULL;
    temp_nlist->data = temp_id;

    // Add to Hash Table
    if (node){
        node->next = temp_nlist;
    }
    else{
        hashTable[key] = temp_nlist;
    }

    return temp_nlist->data;
}

struct id *lookup_hash(char *name, int length) {
    // Hash Function : ((first char ascii code)*(length)) % HASH_TABLE_SIZE
    struct nlist* node;
    int key = ((*name) * (length)) % HASH_TABLE_SIZE;

    // Allocation pointer to node
    node = hashTable[key];

    // While node is not NULL
    while (node) {
        // Check existence
        if (strcmp(node->data->name,name) == 0) {
            // If the token exists, return the data (id structure)
            return node->data;
        }
        if(node->next)
            node = node->next;
        else break;
    }
    return NULL;
}