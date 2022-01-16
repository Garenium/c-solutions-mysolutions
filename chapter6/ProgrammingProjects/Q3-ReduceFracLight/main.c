#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
//This is to ease the maintainability of the code
//Instead of hard-coding if I ever decide to accept larger numbers,
//I should only need to change the type below
//Should prevent buffer and arithmetic overflow
typedef int type;
#define MAX_LENGTH (unsigned int)floor(log10(pow( 2,sizeof(type)*8 ))+1) //LONG_MAX has 20 digits

enum Errors{
    INPUT_LONG,
    INPUT_SHORT,
    NOT_TWO_OPERANDS,
    UNFORMAT_INPUT,
    INVALID_INPUT
};
/*
*   Name: strtonum
*   Return: type (typedef)
*   Purpose: atoi, strtol, stroll return specific types.
*   In order to appease typedef, this function is considered.
*   It is based on a tutorial making a custom atoi function from a YouTube video:
*   https://youtu.be/QyDE7cPycnU?t=144
*/
bool strtonum(char* str, int* result);

void raise_error(enum Errors error);

int main(int argc, char* argv[])
{
    char str[MAX_LENGTH*3+2]; //32 bytes
    char* copy_str = NULL;
    type fraction[2] = {};
    int iterator = 0;

    puts("Reduce fraction to its lowest term program");
    puts("Garenium");
    puts("Jan 10, 2022");
    printf("Type a fraction (number/number): ");
    copy_str = strdup(fgets(str, 30, stdin));
    char* token = NULL; 

    /* printf("MAX_LENGTH: %u\n", MAX_LENGTH); //Debugging purposes */
    /* printf("strlen(str) == %zu\n", strlen(str)); */

    /* [-999, 9999]
     * __________/__________\n
     *   9   +   1    9  +   1 = 20 bytes with long int as input type
     *
     * [-99999999, 999999999]
     *   ____/____\n
     *    4 +1+ 4 +1 = 10 blocks with int as input type*/

    if(strlen(str) > MAX_LENGTH) //MAX_LENGTH IS 10
    {
        raise_error(INPUT_LONG);
        //return -1;
    }
    else if(strlen(str) < 4){
        raise_error(INPUT_SHORT);
        //return -1;
    }
    else{
        token = strtok(str,"/");
        int result = 0;

        while(token != NULL){

            //The program only deals with base-10 numbers, otherwise
            //exit the program
            if(token[0] != '0' && strtonum(token, &result)){ 
                token = strtok(NULL,"/");

                if(token == NULL && iterator == 0) {
                   raise_error(NOT_TWO_OPERANDS);
                   //return -1;
                }
                else if(iterator > 1)
                {
                   raise_error(UNFORMAT_INPUT);
                   //return -1;
                }

                fraction[iterator] = result;

            }
            else{
               raise_error(INVALID_INPUT);
               //return -1;
            }

            
            ++iterator;
            result = 0;
        }

        iterator = 0; //I forgot what this was meant for.
    }


    type numerator = fraction[0];
    type denominator = fraction[1];
    
    if(numerator == denominator)
       puts("1");
    else{
        while(denominator != 0){
            type r = numerator % denominator; 
            numerator = denominator; 
            denominator = r;

        }

        //GCD is numerator now
        if(numerator < 0){
           fraction[0] *= -1; 
           fraction[1] *= -1;
        }


        printf("GCD: %ld\n", (long int)numerator);
        printf("%ld/%ld\n", (long int)fraction[0]/numerator, (long int)fraction[1]/numerator);
    }

    free(copy_str);
    exit(EXIT_SUCCESS);
}

bool strtonum(char* str, int* result){

    bool valid = true;
    int sign = 1;   //positive by default
    int i = 0;  //Initialize the index of a first digit

    //If number is negative, then update the sign
    if(str[0] == '-')
    {
        sign = -1;
        ++i;
    }

    /* printf("%zu\n",strlen(str)); //Debugging purposes */

    while(strlen(str) > i && str[i] != '\n'){
        if(!isdigit(str[i])){
            valid = false;
            break; 
        }
        (*result) = (*result)*10 + str[i] - '0';
        ++i;
    }

    if(valid == true) {
        *result = *result*sign;}

   return valid;
}

//Viable option??
void raise_error(enum Errors error){
    switch(error){
        case 0:
            puts("Error: Input is too long to process.");
            break;
        case 1:
            puts("Error: Input is too short to process.");
            break;
        case 2:
            puts("Error: Input requires two operands to process.");
            break;
        case 3:
            puts("Error: Input not formatted properly");
            break;
        case 4:
            puts("Error: Invalid input.");
            break;
    }

    //If there is no return -1s in the main function after the call is done, 
    //there is another way
    //This helps eliminating repeating return -1s in the main function.
   exit(EXIT_FAILURE);
}
