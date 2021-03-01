IDIR =../headers
DOCSDIR = ../docs
CC=gcc
CPP=g++
CFLAGS=-I$(IDIR)
ODIR=obj
LDIR =../lib

LIBS=-lm

#Uncomment to include dependency
#_DEPS = BSTClassDesign.h 
#_DEPS = SinglyLinkedClassDesign.h
# _DEPS = DoublyLinkedClassDesign.h
_DEPS = GraphClassDesign.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#Uncomment based on the required object file
# _OBJ = BSTClassImplement.o
# _OBJ = SinglyLinkedClassImplement.o
# _OBJ = DoublyLinkedClassImplement.o
_OBJ = GraphClassImplement.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

datastructure: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS) $(LIBS)

documentation:
	doxygen $(DOCSDIR)/docs.conf

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ datastructure 