INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := avl.o main.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/customErrorClass.h avl.h

.PHONY: clean all

all: avl.o main.o customErrorClass.o AVL

clean:
	rm $(OBJS) AVL

avl.o: avl.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
AVL: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)