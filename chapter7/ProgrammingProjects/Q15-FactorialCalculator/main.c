#include <stdio.h>
#include <string.h>
int main(int argc, int* argv[]){

    char input[64] = "\0";
    void *ans = '\0';

    printf("Enter a positive integer: ");
    fgets(input, 62, stdin);

    input[strlen(input)-1] = '\0';

    if(strlen(input) > 60){
        puts("Error: input is too long. The program only accepts 60 characters long");
        return -1;
    }
    else if(input[0] == '-'){
        puts("Error: negative numbers are not accepted");
        return -1;
    }

    printf("Input is %s\n", input);

    if(strspn(input, "0123456789") != strlen(input)){
        puts("Found decimal point");
    }

    return 0;
}
