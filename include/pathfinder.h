/* 
 * File:   pathfinder.h
 * Author: jakobdaugherty
 *
 * Created on December 3, 2015, 11:26 AM
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef PATHFINDER_H
#define	PATHFINDER_H


#define BUFFER 100
    
 

int parser(FILE* inputFile, char map[][BUFFER], int y);
void map_printer(char map[][BUFFER], int y);

#endif	/* PATHFINDER_H */
