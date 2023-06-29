#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    
    char* last_name = NULL;
    char input[20];
    char* p = NULL;
    bool validateInp = false;

    printf("Type your first and last name: ");
    fgets(input, 16, stdin);

    p = input;

    for(int i = 0; i < strlen(input); ++i){
        if(input[i] == ' '){
            last_name = (p+(i+1));
            validateInp = true;
            break;
        }

        putc(input[i],stdout);
    }

    if(!validateInp){
        puts("Your input is invalid");
        return -1;
    }

    if(islower(last_name[0]))
        printf(", %c.\n", toupper(last_name[0]));
    else
        printf(", %c.\n", last_name[0]);
    
    return 0;
}
