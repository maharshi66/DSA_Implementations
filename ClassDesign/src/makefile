IDIR =../headers
CC=gcc
CPP=g++
CFLAGS=-I$(IDIR)
ODIR=obj
LDIR =../lib

LIBS=-lm

#_DEPS = BSTClassDesign.h 
# _DEPS = SinglyLinkedClassDesign.h
_DEPS = DoublyLinkedClassDesign.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = BSTClassImplement.o
# _OBJ = SinglyLinkedClassImplement.o
_OBJ = DoublyLinkedClassImplement.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

datastructure: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 