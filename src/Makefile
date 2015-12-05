IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -g -Wall

ODIR=obj
LDIR =../lib

_DEPS = pathfinder.h parser.h stack.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o parser.o stack.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pathfinder.bin: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
