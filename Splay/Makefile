INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := splay.o mainsplay.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/customErrorClass.h splay.h

.PHONY: clean all

all: splay.o mainsplay.o customErrorClass.o SPLAY

clean:
	rm $(OBJS) SPLAY

splay.o: splay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainsplay.o: mainsplay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
SPLAY: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)