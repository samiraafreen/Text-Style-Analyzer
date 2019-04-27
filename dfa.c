int main(int argc, char* argv []) {
    int state = 0;
    int c;
    FILE *file;
    file = fopen(argv[1], "r");
    if (file) {
        printf("> ");
        while ((c = getc(file)) != EOF){
            printf("%c", c);
            if(state == -1){
                continue;
            }
            if(c == '\n'){
                printf("\n");
                if(state == 3){
                    printf("Correct");
                }
                printf("Incorrect");
                state = 0;
                continue;
            }
            switch (state)
            {
                case 0:
                    state = q0(c);
                    break;
                case 1:
                    state = q1(c);
                    break;
                case 2:
                    state = q0(c);
                    break;
                case 3:
                    state = q0(c);
                    break;
                case 4:
                    state = q0(c);
                    break;
                case 5:
                    state = q0(c);
                    break;
                case 6:
                    state = q0(c);
                    break;
                case 7:
                    state = q0(c);
                    break;
                case 8:
                    state = q0(c);
                    break;
                case 9:
                    state = q0(c);
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
    if (!isupper(x)) return 1;
    /* if it's a hyphen, then go to state 6*/
    elseif ( c == '-') return 6; 
    /* if it's .!? then go to state 3*/
    elseif ( c == '.' || c == '!' || c == '?') return 3; 
    /* if it's a space, then go to state 2*/
    elseif ( c == ' ') return 2;
    /* if it's an apostrophe, then go to state 9*/
    elseif (c == ''') return 9;
    /* if it's a :;, then go to state 4*/
    elseif (c == ',' || c == ':' || c == ';') return 4;
    else return -1;
}

int q2 (char c) {
    /* number, 8*/
    if (ch >= '0' && ch <= '9') return 8;
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
    elseif (isupper(x)) return 1;
    else return -1;
}

int q6 (char c){
    /* capital, 1*/
    int x = c;
    if (!isupper(x)) return 1;
    else return -1;
}

int q7 (char c){
    /* lowercase, 1*/
    /* number, 8*/
    if (!isupper(x)) return 1;
    elseif (ch >= '0' && ch <= '9') return 8;
    else return -1;
}


