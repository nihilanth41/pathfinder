#include <stdio.h>
#include "algorithm.h"

Stack* find_path(Stack* head, int robx, int roby, int gox, int goy, char room[][BUFFER])
{
	int x = robx;  //current x position of the robot
	int y = roby;  //current y position of the robot
	int height = 0;  //height of stack
	if(robx == gox && roby == goy)
	{
		return head;  //have reached destination, return stack that contains path to get there
	}
	if(head != NULL)  //if stack is not empty and we have not reached our destination
	{
		if(room[x++][y] != '#' || room[x++][y] != '*')
		{
			x++;  //increment x
			height = head->size;
			height++;  //new height of the stack
			head = add_new_point(head, x, y, height);  //add this new point to the stack
			room[x][y] = '*';  //make this point in array * to indicate it has been found but not finished
			find_path(head, x, y, gox, goy, room);  //explore from this new point
		}
		else if(room[x][y++] != '#' || room[x++][y] != '*')
		{
			y++;  //increment y
			height = head->size;
			height++;  //new height of the stack
			head = add_new_point(head, x, y, height);  //add this new point to the stack
			room[x][y] = '*';  //make this point in array * to indicate it has been found but not finished
			find_path(head, x, y, gox, goy, room);  //explore from this new point
		}
		else if(room[x--][y] != '#' || room[x++][y] != '*')
		{
			x++;  //increment x
			height = head->size;
			height++;  //new height of the stack
			head = add_new_point(head, x, y, height);  //add this new point to the stack
			room[x][y] = '*';  //make this point in array * to indicate it has been found but not finished
			find_path(head, x, y, gox, goy, room);  //explore from this new point
		}
		else if(room[x][y--] != '#' || room[x++][y] != '*')
		{
			y--;  //increment y
			height = head->size;
			height++;  //new height of the stack
			head = add_new_point(head, x, y, height);  //add this new point to the stack
			room[x][y] = '*';  //make this point in array * to indicate it has been found but not finished
			find_path(head, x, y, gox, goy, room);  //explore from this new point
		}
		else
		{
				room[x][y] = '#';  //put new wall in this spot to indicate we have finished discovering from this spot and it is not what we want
				head = delete_point(head);  //take this point off of the stack since it's not what we want and it doesn't get us there
				x = head->x;  //new x-coord for where we are
				y = head->y;  //new y-coord for where we are
				find_path(head, x, y, gox, goy, room);  //explore from this new point
		}
	}
	else  //if the stack is empty, make new stack
	{
		int size = 0;  //size of the stack
		head = add_new_point(head, robx, roby, size);  //first point in stack is location of the robot  Source Vertex
	}
	return head;
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
		height++;
		point->size = height;
		head = point;
		point->next = NULL;
	}
	return head;
}

Stack* delete_point(Stack* head)
{
	if(head->size == 0)
	{
		return NULL;
	}
	Stack* temp;
	temp = head;
	head = temp++;
	free(temp);
	head->size--;
	return head;
}

void print_path(Stack* head)
{
	while(head != NULL)  //while stack is not empty
	{
		if(head->x > head->next->x)
		{
			printf("The robot moved one spot to the Right in move %d", head->size);
			head = delete_point(head);
			print_path(head);
		}
		else if(head->y > head->next->y)
		{
			printf("The robot moved one spot Down in move %d", head->size);
			head = delete_point(head);
			print_path(head);
		}
		else if(head->x < head->next->x)
		{
			printf("The robot moved one spot to the Left in move %d", head->size);
			head = delete_point(head);
			print_path(head);
		}
		else if(head->y < head->next->y)
		{
			printf("The robot moved one spot Up in move %d", head->size);
			head = delete_point(head);
			print_path(head);
		}
	}
}
