CC=g++
CFLAGS=-W -Wall -ansi -pedantic -g -std=c++11 
LDFLAGS=
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
 
all: $(EXEC)
 
main: $(OBJ)
	$(CC) -o $@  $^ $(LDFLAGS)
 
main.o: main.cpp Symbole.h Lexer.h Automate.h  State.h
	$(CC) -o $@ -c $< $(CFLAGS)
 
.PHONY: clean mrproper
 
clean:
	rm -rf *.o
 
mrproper: clean
	rm -rf $(EXEC)