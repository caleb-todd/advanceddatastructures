INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := dsw.o main.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/customErrorClass.h dsw.h

.PHONY: clean all

all: dsw.o main.o customErrorClass.o DSW

clean:
	rm $(OBJS) DSW

dsw.o: dsw.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<
DSW: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)