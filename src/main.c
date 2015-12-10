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

// Copy map to buffer
int i,j;
char mapBuf1[BUFFER][BUFFER];
char mapBuf2[BUFFER][BUFFER];
for(i=0; i<BUFFER; i++) {
	for(j=0; j<y; j++) {
		mapBuf1[i][j] = map[i][j];
		mapBuf2[i][j] = map[i][j];
	}
}


int Sx,Sy,Fx,Fy;
int goSx,goSy,goFx,goFy;
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

Stack *head1 = NULL;
head1 = find_path(head1, Sx, Sy, goSx, goSy, mapBuf1);
add_stack(mapBuf1, head1, '$');
//map_printer(mapBuf1,y);
//head1 = print_path(head1);




Stack *head2 = NULL;
head2 = find_path(head2, Fx, Fy, goFx, goFy, mapBuf2);
//printf("\nHead 2 size: %d\n", head2->size);
add_stack(mapBuf1, head2, '@');
mapBuf1[goFx][goFy] = 'L';
mapBuf1[Fx][Fy] = 'F';
mapBuf1[goSx][goSy] = 'E';
mapBuf1[Sx][Sy] = 'S';
map_printer(mapBuf1,y);
//head2 = print_path(head2);

//add_stack(mapBuf2, head1, '^');
//map_printer(mapBuf2,y);

//head1 = find_path(head1, Fx, Fy, goFx, goFy, mapBuf2);
//add_stack(map, head1, '$');
//add_stack(map, head1, '+');



if( fclose(fp) != 0 )
{
	exit(-1); //file failed to close 
}
printf("\n");

return (EXIT_SUCCESS);
}



