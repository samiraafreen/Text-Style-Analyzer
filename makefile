all: dfa.c 
	gcc -g -Wall -o dfa dfa.c

clean: 
	$(RM) dfa
