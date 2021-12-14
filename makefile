all: compile run

compile:
	gcc -I ./include -o ./bin/shell ./src/shell.c ./src/Execute.c ./src/Parsing.c 

run:
	./bin/shell
