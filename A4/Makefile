INCLUDE_DIRS := -IIncludes -IAVL
CC := g++
CFLAGS := $(INCLUDE_DIRS) -std=c++11

OBJS := AVL/avl.o hash.o mainHash.o
DEPS := AVL/avl.h hash.h

.PHONY: clean all

all: HASH

clean:
	rm -f $(OBJS) HASH

avl.o: AVL/avl.cpp $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

hash.o: hash.cpp $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

mainHash.o: mainHash.cpp $(DEPS)
	$(CC) -c -o $@ $(CFLAGS) $<

HASH: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)