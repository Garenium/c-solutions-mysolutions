#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef long double type;

void raiseError(int errorNo){
    switch(errorNo){
      case 0:
         puts("Ignored because input is not a number");
         break;
      case 1:
         puts("Ignored because value is too large.");
         break;
    }
}


int main()
{
    type max = -1;
    type comp2Max = -1;
    char str[20];
    char* endPtr = NULL;
    bool isZero = false;    
    int c = 0;
    bool firstInput = true;
    enum errorMsgs;

    puts("Type a number until typing enter to get a max number!");
    puts("Author: Garenium");
    puts("Date: Feb 28, 2022\n");


    /* printf("long double size = %zu", sizeof(type)); */

    while(!isZero){
        printf("Enter a number: ");
        fgets(str, 15, stdin);
        
        //If the input is too long 
        //and the \n is overwritten
        //Flush the buffer
        if(str[strlen(str)-1] != '\n')
            while((c = getchar()) != '\n' && c != EOF); //flushing
        else{

            if(str[0] == '0' && strlen(str) > 2)
            {
              raiseError(0);
              continue;
            }

            str[strlen(str)-1]='\0';

            //control if input is "\0"
            if(str[0] == '\0'){
                //Ignore first input if it's \0
                if(firstInput){  //if true
                    raiseError(0);
                    continue;
                }
                else{
                    isZero = true;
                    break;
                }
            }
        }
        

        comp2Max = strtold(str, &endPtr);
        /* printf("comp2Max: %Lf\n",comp2Max); //debugging */ 
        /* printf("endPtr: %s\n", endPtr); //debugging */

        if(strcmp(endPtr, "")){
            raiseError(0);
            continue;}

        if(strlen(str) >= 10){
            raiseError(1);
           continue;}

        if(max < comp2Max)
            max = comp2Max;
        /* printf("Max: %Lf \n", max); */
        firstInput = false;
     
    } 

    if(max - (int)max == 0.0){ //Is it an integer?
        /* puts("subtracting"); */
        long long int mx = max;
        printf("\nThe largest number entered was %lld\n", mx);
    }
    else{ //or not?
        printf("\nThe largest number entered was %Lf\n", max);
    }

    return 0;
}

