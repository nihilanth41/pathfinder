#include "parser.h"
#include "colors.h"
#include "algorithm.h"

int parser(FILE* inputFile, char map[][BUFFER], int y){
    
    char charByChar; //holds current char 
    int xpos = 0;
    int ypos = 0;//initalize the 
    
    
    do {
        charByChar = fgetc(inputFile);//gets next character 
        if(charByChar == '\n' || charByChar == '\t'){
            //then change x and y positions BC next char will be newline
            map[xpos][ypos] = charByChar;
            
            ypos++;
            xpos = 0;
        }
        else{
            map[xpos][ypos] = charByChar;
            xpos++;
        }
        
    } while (charByChar != EOF);

    y = ypos;
    //printf("\nY is %d\n", y);
    return(y);
}//end parser


void map_printer(char map[][BUFFER], int y){
    int xpos = 0;
    int ypos = 0;
    printf("\nThis is the map\n");
    while(ypos < y-1){
        if(map[xpos][ypos] == '\n'){
            ypos++;
            xpos = 0;
            printf("\n");
        }
	else{
		if(map[xpos][ypos] == '#') 
		{
			printf(ANSI_COLOR_GREEN "#" ANSI_COLOR_RESET);
		}
		else 
		{
			printf("%c", map[xpos][ypos]);
        	}
	xpos++;
	}
    }
}


