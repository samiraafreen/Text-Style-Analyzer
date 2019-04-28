#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int q0(char c){
    /* transition function from state 0 to state 1*/
    /* checks if the first character is a capital letter*/
    int x = c;
    if (isupper(x)) {
        /* if it is, go to state 1*/
        return 1;
    } else return -1;
}

int q1(char c){
    /* if it's lowercase, then loop back to state 2*/
    int x = c;
    if (islower(x)) return 1;
    /* if it's a hyphen, then go to state 6*/
    else if ( c == '-') return 6; 
    /* if it's .!? then go to state 3*/
    else if ( c == '.' || c == '!' || c == '?') return 3; 
    /* if it's a space, then go to state 2*/
    else if ( c == ' ') return 2;
    /* if it's an apostrophe, then go to state 9*/
    else if (c == '\'') return 9;
    /* if it's a :;, then go to state 4*/
    else if (c == ',' || c == ':' || c == ';') return 4;
    else return -1;
}

int q2 (char c) {
    /* number, 8*/
    if (c >= '0' && c <= '9') return 8;
    /* lowercase or capital, 1*/
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    else return -1;
}

int q3 (char c) {
    /* space, 5*/
    if (c == ' ') return 5;
    else return -1;
}

int q4 (char c ){
    /* space, 7*/
    if (c == ' ') return 7;
    else return -1;
}

int q5 (char c){
    /* space, 0*/
    /* capital, 1*/
    int x = c;
    if (c == ' ') return 0;
    else if (isupper(x)) return 1;
    else return -1;
}

int q6 (char c){
    /* lowercase or capital, 1*/
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    else return -1;
}

int q7 (char c){
    /* lowercase or capital, 1*/
    /* number, 8*/
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    else if (c >= '0' && c <= '9') return 8;
    else return -1;
}

int q8 (char c){
    /* number, 8*/
    if (c >= '0' && c <= '9') return 8;
    /* space, 2*/
    else if (c == ' ') return 2;
     /* ;:,, 4*/
    else if (c == ',' || c == ':' || c == ';') return 4;
     /* .!?, 3*/
    else if (c == '.' || c == '!' || c == '?') return 3;
    else return -1;
}

int q9 (char c){
    /* lowercase or capital, 1*/
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    /* space, 2*/
    else if (c == 'c') return 2;
    /* .!? , 3*/
    else if (c == '.' || c == '?' || c == '!') return 3;
    else return -1;
}

int main(int argc, char* argv []) {
    if(argc != 2){
        printf("No input given \n");
        exit(1);
    }
    int state = 0;
    int c;
    FILE *file;
    file = fopen(argv[1], "r");
    if (file) {
        printf("> ");
        while ((c = getc(file)) != EOF){
            printf("%c", c);
            if(state == -1 && c != '\n'){
                continue;
            }
            if(c == '\n'){
                if(state == 3){
                    printf("Correct\n");
                }
                else{
                    printf("Incorrect\n");
                }
                state = 0;
                printf("\n> ");
                continue;
            }
            switch (state)
            {
                case 0:
                /* this is the start state */
                    state = q0(c);
                    break;
                case 1:
                    state = q1(c);
                    break;
                case 2: 
                    state = q2(c);
                    break;
                case 3:
                /* this is the final state */
                    state = q3(c);
                    break;
                case 4:
                    state = q4(c);
                    break;
                case 5:
                    state = q5(c);
                    break;
                case 6:
                    state = q6(c);
                    break;
                case 7:
                    state = q7(c);
                    break;
                case 8:
                    state = q8(c);
                    break;
                case 9:
                    state = q9(c);
                    break;
                default:
                    break;
            }
        }
        fclose(file);
    }
}
//can capitals come after hyphens? like Ray-Bans
//why only one apostrophe allowed per word? y'all'dn't've
//how many spaces allowed after a line?
//only double spaces after sentence?

