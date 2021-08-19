#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv){
    
    char input[10];
    char* endPtr;
    
    printf("Type wind speed (in knots): ");
    fgets(input, 8, stdin);
    
    //puts("");
    //printf("%s", input);
    input[strlen(input)-1]='\0';
    //printf("%s", input);

    int speed = strtol(input, &endPtr, 10);

    if(strcmp(endPtr, "") || input[0] == '\0' || strlen(input) > 5){
        puts("Error: Invalid input. [Line 21]");
        return -1;
    }

    if(speed < 1) 
        puts("Calm");
    else if(speed >= 1 && speed <= 3)
        puts("Ligh air");
    else if(speed >= 4 && speed <= 27) 
        puts("Breeze");
    else if(speed >= 28 && speed <= 47) 
        puts("Gale");
    else if(speed >= 48 && speed <= 63)
        puts("Storm");
    else
        puts("Hurricane");

    return 0;
}
