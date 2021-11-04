#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef long double type;

int main()
{
    type max = LLONG_MIN;
    type comp2Max = -1;
    char str[20] = {'\0'};
    char* endPtr = NULL;
    bool isZero = false;    
    int c = -1;


    /* printf("long double size = %zu", sizeof(type)); Debugging */

    while(!isZero){
        printf("Enter a number: ");
        fgets(str, 15, stdin);
        
        //If the input is too long 
        //and the \n is overwritten
        //Flush the buffer
        if(str[strlen(str)-1] != '\n')
            while((c = getchar()) != '\n' && c != EOF);
        else
        str[strlen(str)-1]='\0';

        if(str[0] == '\0') //Check if str is empty
            isZero = true;
        else{
            comp2Max = strtold(str, &endPtr);

            if(strcmp(endPtr, "")){
                puts("Ignored because input is not a number");
                continue;}

            if(strlen(str) >= 10){
               puts("Ignored because value is too large.");
               continue;}

            if(max < comp2Max)
                max = comp2Max;  
        }
    } 

    if(max == LLONG_MIN) { 
	    printf("\nError: There was no valid input to determine the largest number."); } 
    else{ 
	    printf("\nThe largest number entered was %Lg\n", max); }

    return 0;
}

