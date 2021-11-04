#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef long double type;

void print_error(int errorNo){
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
    type max = LLONG_MIN;
    type comp2Max = -1;
    char inputBuff[20] = {'\0'};
    char tempBuff[50] = {'\0'};
    char outputBuff[50] = {'\0'};
    char* endPtr = NULL;
    bool isZero = false;    
    int c = -1;


    puts("Type a number until typing enter to get a max number!");
    puts("Author: Garenium");
    puts("Date: Nov 5, 2021\n");

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
                for(size_t i = 0; i < strlen(tempBuff); ++i){

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

        if(inputBuff[0] == '\0') //Check if inputBuff is empty
            isZero = true; //exit the loop
        else{
            if(strlen(inputBuff) > 1 && inputBuff[0] == 0) {
                //Not allowing inputs like 0343, 02, etc.
                print_error(0); 
                continue;
            }else{
                comp2Max = strtold(inputBuff, &endPtr); //Convert the string to a long double

                if(strcmp(endPtr, "")){ //If a non-digit character is found
                    print_error(0);                    
                    continue;
                }

                if(strlen(inputBuff) >= 10){ //Checking for length
                    print_error(1);
                    continue;
                }

                if(max < comp2Max)
                    max = comp2Max;
            }

        }
    } 

    if(max == LLONG_MIN) { //If max was never reassigned
	  printf("\nError: There was no valid input to determine the largest number.\n"); } 
    else{ 
          printf("\nThe largest number entered was %s\n", outputBuff); }

    return 0;
}
