/******************************************************
 * File Name   : subc.h
 * Description
 *    This is a header file for the subc program.
 ******************************************************/

#ifndef __SUBC_H__
#define __SUBC_H__

#define KEYWORD   0
#define UNDEFINED 1
#define ID_       2

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

/* structure for ID */
typedef struct id {
	int lexType;
	char *name;
	int count;
} id;

/* For hash table */
unsigned hash(char *name);
struct id *enter(int lexType, char *name, int length);
struct id *lookup(char *name);

int read_line();


#endif