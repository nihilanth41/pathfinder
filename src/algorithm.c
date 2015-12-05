#include <stdio.h>
#include "stack.h"

Stack* find_path(int robx, int roby, int gox, int goy, char room[x, y])
{
	Stack* head = NULL;  //make empty stack
	int size = 0;  //size of the stack
	head = add_new_point(head, robx, roby, size);  //first point in stack is location of the robot
}

Stack* add_new_point(Stack* head, int i, int j, int height)
{
	Stack* point = NULL;
	Stack* temp;
	point = malloc(sizeof(Stack));  //malloc new structure for the newly discovered point
	if(head != NULL)  //while stack not empty
	{
		point->x = i;  //put in new x-coord
		point->y = j;  //put in new y-coord
		point->size = height++;  //increase the size of the stack by one
		temp = head;
		head = point;  //head now points to new node
		point->next = temp;  //next pointer points to old head
	}
	else  //if stack is empty, add first node
	{
		height = height++;
		point->size = height;
		head = point;
		point->next = NULL;
	}
	return head;
}

Stack* delete_point(stack* point)
{
	
}
