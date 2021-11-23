C=clang++
FLAGS=-std=c++1y -stdlib=libc++ -c -g -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function	#flags for compiler (turns .c files into .o files
LDFLAGS=-std=c++1y -stdlib=libc++ -lc++abi	#flags for linker (grabs .o files and links them

all: main.o graph.o 
	$(C) $(LDFLAGS) main.o graph.o -o main

main.o: main.c
	$(C) $(FLAGS) graph.c

graph.o: graph.c
	$(C) $(FLAGS) graph.c

clean:
	rm -f *.o
