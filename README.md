# Text Style Checker DFA

This C program implements a DFA that checks the style of a text file. For every line of text, it prints the line and returns "Correct" if the text conforms to the punctuation rules determined by the Optional Programming Assignment 1 document, and "Incorrect" if it does not conform.

## Running the Program

Compile the dfa.c file using the makefile. Run ./dfa with the input text file name.

## Code Structure

The main function reads in a file one character at a time, stores state in an integer variable, and calls a specific function according to the state and passes the current character input as an argument to the state function. The state functions return the integer value of the new state after the current character is read. When a new line character is read, the main function evaluates whether or not the current state is an accepting state, and accepts or rejects the line accordingly.

## Known Discrepancies

* Accepts text that contains capital letters after hyphens in words, such as "Ray-Bans".
* Accepts text that contains multiple apostrophes in one word, such "y'all'd've".
* Accepts text that has up to two spaces at the end of a line.
* Accepts the empty string.

## Authors

* Eura Choi
* Samira Afreen
