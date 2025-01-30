INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := bstP.o mainP.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/customErrorClass.h bstP.h

.PHONY: clean all

all: bstP.o mainP.o customErrorClass.o BST

clean:
	rm $(OBJS) BST

bstP.o: bstP.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainP.o: mainP.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
BST: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)