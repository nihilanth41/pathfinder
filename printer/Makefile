mode: main.c parser.o pathfinder.h
	gcc -Dexecute_mode -Wall -O1 main.c parser.o -o finalProject
	
	
parser.o: parser.c
	gcc -c parser.c
	
clean:
	rm -rf *.o finalProject
