#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "algorithm.h"


int main(int argc, char** argv) {
  
if(argc != 3) 
{
	printf("Usage is: %s <map file> <interference>\n", argv[0]);
	exit(-1);
}

FILE* fp = fopen(argv[1], "r");
if(fp == NULL) 
{
	exit(-1); //file failed to open
}
int R = atoi(argv[2]);
char map[BUFFER][BUFFER];//the array we will store the map in 
int y=0;
y = parser(fp, map, y);

int Sx,Sy,Fx,Fy;
int goSx,goSy,goFx,goFy;
int i,j=0;
for(i=0; i<BUFFER; i++) 
{
	for(j=0; j<y; j++) 
	{
		switch(map[i][j]) 
		{
			case 'S': 
				{
					Sx=i;
					Sy=j;
					break;
				}
			case 'E': 
				{
					goSx=i;
					goSy=j;
					break;
				}
			case 'F':
				{
					Fx=i;
					Fy=j;
					break;
				}
			case 'L':
				{
					goFx=i;
					goFy=j;
					break;
				}
			default: break;
		}
	}
}
//Check for interference
if(isInterference(Fx, Fy, Sx, Sy, R) == 1) 
{
	printf("Robot initial positions interfere with eachother (<=%d)\n", R);
	exit(-1);
}
Stack *head = NULL;
head = find_path(head, Sx, Sy, goSx, goSy, map);
add_stack(map, head);
map_printer(map,y);

if( fclose(fp) != 0 )
{
	exit(-1); //file failed to close 
}
printf("\n");

return (EXIT_SUCCESS);
}

