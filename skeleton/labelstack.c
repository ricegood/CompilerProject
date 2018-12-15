/***************************************************************
 * File Name    : labelstack.c
 * Description
 *      This is an implementation file for label stack
 *		to save the label of loop statement break/continue.
 *
 ****************************************************************/

#include "subc.h"

void push_label_stack(struct label_node** top, int label_number) {
	struct label_node *new = malloc(sizeof(struct label_node));
	new->label_number = label_number;
	new->prev = *top;
	*top = new;
}

void pop_label_stack(struct label_node** top) {
	struct label_node *temp = *top;
	if (temp) {
		*top = (*top)->prev;
		free(temp);
	}
}

int get_break_label_number() {
	if (break_label_stack) {
		return break_label_stack->label_number;
	}
	else {
		printf("ERROR : break label stack null!\n");
		return -1;
	}
}

int get_continue_label_number() {
	if (continue_label_stack) {
		return continue_label_stack->label_number;
	}
	else {
		printf("ERROR : continue label stack null!\n");
		return -1;
	}
}