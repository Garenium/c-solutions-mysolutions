#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef long double type;

int main()
{
    type max = LLONG_MIN;
    type comp2Max = -1;
    char inputBuff[20] = {'\0'};
    char tempBuff[50] = {'\0'};
    char outputBuff[50] = {'\0'};
    char* endPtr = NULL;
    bool isZero = false;    
    int c = -1;

    /* printf("long double size = %zu", sizeof(type)); Debugging */

    while(!isZero){
        printf("Enter a number: ");
        fgets(inputBuff, 15, stdin);
        
        //If the str input is \n
        //Assign the last inputted max value to tempBuff
        if(inputBuff[0] == '\n'){ //Last input
            snprintf(tempBuff, 20, "%Lf",max);  //Write the last recorded max to outputBuff
            //We want to output outputBuff identically to input
            
            //Due to the format specifier being %LF, 34 will be 34.000000
            //So we need to make outputBuff identical to inputBuff
            if(*tempBuff == (int)(*tempBuff)){ //Checking if the numbers are equal without trailing zeros

                //assign the characters until the character period is found
                for(size_t i = 0; i < sizeof(tempBuff)/sizeof(type); ++i){

                    if(tempBuff[i] == '.') { break; }
                    else{ outputBuff[i] = tempBuff[i]; }
                    
                }

            }
        }

        
        //If the input is too long 
        //and the \n is overwritten
        //Flush the buffer to allow the user retype 
        //a number again
        if(inputBuff[strlen(inputBuff)-1] != '\n')
            while((c = getchar()) != '\n' && c != EOF);
        else
        inputBuff[strlen(inputBuff)-1]='\0';

        if(inputBuff[0] == '\0') //Check if tempBuff is empty
            isZero = true; //exit the loop
        else{
            comp2Max = strtold(inputBuff, &endPtr); //Convert the string to a long double

            if(strcmp(endPtr, "")){ //If a non-digit character is found
                puts("Ignored because input is not a number");
                continue;}

            if(strlen(inputBuff) >= 10){ //Checking for length
               puts("Ignored because value is too large.");
               continue;}

            if(max < comp2Max)
                max = comp2Max;
        }
    } 

    if(max == LLONG_MIN) { //If max was never reassigned
	  printf("\nError: There was no valid input to determine the largest number.\n"); } 
    else{ 
          printf("\nThe largest number entered was %s\n", outputBuff); }

    return 0;
}
