#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef long double type;

int main()
{
    type max = LLONG_MIN;
    type comp2Max;
    char str[20];
    char* endPtr;
    bool isZero = false;    
    int c;

    /* printf("long double size = %zu", sizeof(type)); */

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

        //if(!strcmp(str, "0"))
        if(str[0] == '\0')
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

    printf("\nThe largest number entered was %Lg\n", max);

    return 0;
}

