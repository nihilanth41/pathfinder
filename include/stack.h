#ifndef __STACK_H
#define __STACK_H

// Struct to store x,y coords & vertex color 
typedef struct vertex_ {
	int x;
	int y;
	char color;
} vertex;

// Struct which will be the container for the stack 
typedef struct node_ { 
	struct vertex_ *v 
	struct node_ *next
} node;

// Stack type 
typedef struct stack_ {
	unsigned int size;
	struct node_ *stack
} stack;

stack* create_stack()
void push(stack *s, vertex *v);
void pop(stack *s)
vertex* top(stack *s)
int isEmpty(stack *s) 

#endif 
