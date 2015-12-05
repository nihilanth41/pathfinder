#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "parser.h"
#include "pathfinder.h"

int main(int argc, char** argv) {
  
    if(argc != 2) {
	    printf("Usage is: %s <map file>\n", argv[0]);
	    exit(-1);
    }
    

    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        exit(-1); //file failed to open
    }
    
    char map[BUFFER][BUFFER];//the array we will store the map in 
    int y=0;
    y = parser(fp, map, y);
    map_printer(map, y);
    
    if( fclose(fp) != 0 ){
        exit(-1); //file failed to close 
    }
    printf("\n");

    //test stack functions
    //create empty stack
    stack *s = create_stack();
    if(isEmpty(s))
	    printf("Empty stack!\n");
    
    //create vertex and populate
    vertex *v = malloc(sizeof(vertex));
    v->x = map[0][0];
    v->y = map[0][0];
    v->color = '#';
    //push vertex to stack
    push(s, v);

    if (!(isEmpty(s)))
	    printf("Stack not empty!\n");

    //get top element of stack
    vertex *topv = top(s);
    printf("x: %d, y: %d c: %c\n", topv->x, topv->y, topv->color);

    pop(s);
    if(isEmpty(s))
	    printf("Empty stack!\n");


    return (EXIT_SUCCESS);
}

