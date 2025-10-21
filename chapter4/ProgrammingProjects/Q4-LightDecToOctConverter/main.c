#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void printIntro(){
    puts("Light dec to octal converter");
    puts("Author: Garenium");
    puts("Date: Jun 5, 2021\n");
}



bool validateInput(int* x ,int argc, char* argv[]){

    char str[10];
    char* endPtr;

    /* printf("argc: %d\n", argc); */

    //Two conditions for bashscript use or without
    if(argc == 2)
    {
        *x = strtol(argv[1], &endPtr, 10);
        printf("argv[1] = %d\n", *x);
        
        if(strcmp(endPtr, ""))
            return true;

    }
    else{
        printf("Enter a number between 0 and 32767: ");
        fgets(str, 8, stdin);
        str[strlen(str)-1]='\0';
        
        *x = strtol(str, &endPtr, 10);

        if(str[0] == '0' || str[0] == '\0' || strcmp(endPtr, "")){
            return true; 
        } 
        else
        {
            return false;
        }
    } 
}


int main(int argc, char* argv[])
{
    int* x = 0;
    bool validNumber = false;
    
    while(!validNumber){
        validNumber = validateInput(x, argc, argv);

        //If it's a number, validate the range
        if(!validNumber){
            puts("Error: Input is not a number");
        }
        else if(*x < 0 || *x > 32767){
            puts("Error: Out of range");
        }
 
    }
   
    /* printf("Number: %d\n", x); //Debugging to check the content of x */
    printf("In octal, your number is: 0o%o\n", *x);

    return 0;
}
