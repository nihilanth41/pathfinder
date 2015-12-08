#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#include "parser.h"

typedef struct node_ {
	int x;
	int y;
	int size;
	struct node_ *next;
} Stack;

Stack* find_path(Stack* head, int robx, int roby, int gox, int goy, char room[][BUFFER]);
Stack* add_new_point(Stack* head, int i, int j, int height);
Stack* delete_point(Stack* head);
void print_path(Stack* head);
void add_stack(char map[][BUFFER], Stack *s);

#endif
