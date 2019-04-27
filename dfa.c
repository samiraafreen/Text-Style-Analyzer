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
    return;
}
int q3(char c){
    switch (c)
    {
        case ' ':
            /* code */
            break;
    
        default:
            break;
    }
}
