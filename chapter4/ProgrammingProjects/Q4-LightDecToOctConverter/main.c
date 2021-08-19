#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    /*puts("Light dec to octal converter");
    puts("Author: Garenium");
    puts("Date: Jun 5, 2021\n");*/

    char str[10];
    char* endPtr;
    int x;
    bool notNumber = false;

    //Two conditions for bashscript use or without
    if(argc == 2)
    {
        x = strtol(argv[1], &endPtr, 10);
        printf("argv[1] = %d\n", x);
        
        if(strcmp(endPtr, ""))
            notNumber = true;

    }
    else{
        printf("Enter a number between 0 and 32767: ");
        fgets(str, 8, stdin);

        str[strlen(str)-1]='\0';
        
        x = strtol(str, &endPtr, 10);

        if(strcmp(endPtr, "") || str[0] == '\0')
            notNumber = true; 
    } 

    //printf("x = %d\n", x); Debugging purposes

    //Validating the range
    if(x < 0 || x > 32767){
        puts("Out of range. [Line 29]");
        return -1;
    }
    else if(notNumber == true){
        puts("Error: Input is not a number [Line 23]");
        return -1;
    }
    
    /* printf("Number: %d\n", x); //Debugging to check the content of x */
    printf("In octal, your number is: 0o%o\n", x);

    return 0;
}
