 # -*- MakeFile -*-
CC=gcc
AR=ar
FLAGS=-Wall -g
OBJECTS_LIB=Trie.o
OBJECTS_MAIN=main.o

all:libMyTrie.a  frequency
frequency: $(OBJECTS_MAIN) libMyTrie.a
	$(CC) $(FLAGS) -o frequency $(OBJECTS_MAIN) libMyTrie.a -lm
libMyTrie.a: $(OBJECTS_LIB)
	$(AR) -rcs libMyTrie.a $(OBJECTS_LIB)
Trie.o:Trie.c Trie.h
	$(CC) $(FLAG) -c Trie.c
main.o:main.c Trie.h
	$(CC) $(FLAG) -c main.c

clean:
	rm -f *.o *.a *.so frequency

.PHONY:clean all