#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

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

    return (EXIT_SUCCESS);
}

