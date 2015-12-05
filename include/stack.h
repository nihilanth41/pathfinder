#ifndef __STACK_H
#define __STACK_H

typedef struct node_ {
	int size;
	int x;
	int y;
	struct node_ *next;
} Stack;

void push(stack *s, int x, int y);
void pop(stack *s)
stack* create_stack(int x, int y);
int isEmpty(Stack *s 

#endif 
