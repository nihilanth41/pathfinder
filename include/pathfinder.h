#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "colors.h"

#ifndef PATHFINDER_H
#define	PATHFINDER_H

#define BUFFER 100

int parser(FILE* inputFile, char map[][BUFFER], int y);
void map_printer(char map[][BUFFER], int y);

#endif	/* PATHFINDER_H */
