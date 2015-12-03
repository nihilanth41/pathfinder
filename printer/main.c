/* 
 * File:   main.c
 * Author: jakobdaugherty
 *
 * Created on December 3, 2015, 11:24 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "pathfinder.h"



/*
 * 
 */
int main(int argc, char** argv) {
  
    int y = 0;
    /*
    if(argc != 2){
        exit(-1);
    }
    */
    printf("\nPlease input the filename\n");
    char file_name;
    scanf("%s", &file_name);
    FILE* inputFile = fopen(&file_name, "r");
    if(inputFile == NULL){
        exit(-1);//file failed to open
    }
    
    
    
    char map[BUFFER][BUFFER];//the array we will store the map in 
    
    y = parser(inputFile, map, y);
    
    map_printer(map, y);
    
    
    
    if( fclose( inputFile ) != 0 ){
        exit(-1); //file failed to close 
    }
    
    printf("\n");

    return (EXIT_SUCCESS);
}

