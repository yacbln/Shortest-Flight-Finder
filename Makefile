C=clang++
FLAGS=-std=c++1y -stdlib=libc++ -c -g -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function	#flags for compiler (turns .c files into .o files
LDFLAGS=-std=c++1y -stdlib=libc++ -lc++abi	#flags for linker (grabs .o files and links them)

all: main.o graph.o airport.o route.o fileio.o
	$(C) $(LDFLAGS) main.o graph.o airport.o route.o fileio.o -o main

test: test.o graph.o airport.o route.o fileio.o
	$(C) $(LDFLAGS) test.o graph.o airport.o route.o fileio.o -o test

main.o: main.cpp
	$(C) $(FLAGS) main.cpp

test.o: test.cpp
	$(C) $(FLAGS) test.cpp

graph.o: graph.cpp
	$(C) $(FLAGS) graph.cpp

airport.o: airport.cpp
	$(C) $(FLAGS) airport.cpp

route.o: route.cpp
	$(C) $(FLAGS) route.cpp

fileio.o: fileio.cpp
	$(C) $(FLAGS) fileio.cpp

clean:
	rm -f *.o
