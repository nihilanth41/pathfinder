#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// Return: pointer to an empty stack 
stack* create_stack() {
	stack *sPtr = malloc(sizeof(stack));
	sPtr->size=0;
	sPtr->stack=NULL;
	return sPtr;
}

// Param: s - pointer to a stack 
// Param: v - vertex to be added to the stack 
void push(stack *s, vertex *v) {
	//check for NULL ptr 
	assert(s != NULL);
	node *newNode = malloc(sizeof(node));
	if(newNode == NULL) {
		printf("Malloc failed");
		exit(-1);
	}
	else {
		newNode->v = v;
		newNode->next = s->stack;
		s->stack = newNode;
		s->size++;
	}
}

// Param: s - pointer to a stack
void pop(stack *s) {
	assert(s != NULL);
	node *top = s->stack;
	//if stack is empty:
	if(top == NULL) {
		return;
	}
	else {
		s->stack = top->next;
		free(top);
		s->size--;
	}
}

// Param: s - pointer to a stack
// Return: the vertex stored at the top of the stack 
vertex* top(stack *s) {
	assert(isEmpty(s) == 0);
	assert(s->stack != NULL);
	return s->stack->v;
}

// Param: s - a pointer to a stack 
// Return: 1 if stack is empty, 0 otherwise 
int isEmpty(stack *s) {
	return s->stack == NULL ? 1 : 0;
}




