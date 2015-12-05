#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef __PARSER_H
#define __PARSER_H
#define BUFFER 100

int parser(FILE* inputFile, char map[][BUFFER], int y);

#endif
