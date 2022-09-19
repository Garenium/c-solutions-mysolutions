//Calculations tested with https://www.calculatorsoup.com/calculators/math/gcf.php
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "Header.h"

//Max characters in INT_MIN is 11
//11 * 2 + 1 (space between two nums) = 23
//And another four for extra space 24+4=27
//
//Calculator soup's max value is 1 x 10^13 (10,000,000,000,000)
//That will be 14 characters (without commas of course)
//14 _ 14
//14 + 1 + 14 = 29 chars
//So 27 chars is more than enough
#define MAX_BUFFER 27

bool isNotNumber(char* str)
{
    bool condition = false;
    int negException = 0;
    int spaceException = 0;
    for(size_t i = 0; i < strlen(str); ++i){

        if(str[i] == '-') {
            i++;
            negException++;
            if(negException > 1){
                condition = true;
                break;
            }
        }
        else if(str[i] == ' '){
            i++;
            spaceException++;
            if(spaceException > 1){
                condition = true;
                break;
            }
        }
        else if(!isdigit(str[i])){
            condition = true;
            break;
        }
    }

    return condition;
}

void printTokensToDebug(char* firstToken, char* secondToken){
    printf("first Token: %s\n", firstToken);
    printf("second Token: %s\n", secondToken);
}
int main(int argc, char* argv[])
{
    //Max no. of digits in MAX_IN is 10, since there are two integers involved and negative numbers are valid, a bump up to 27 is appropriate.
    char input[MAX_BUFFER];   
    char str[MAX_BUFFER];
    long long twoInts[2]; 
    int count = 0;
    char *firstToken;
    char *secondToken;
    char *endPtr; 
    bool argCmd = false;

    printf("%d argument(s)\n", argc);

    //INPUT
    //Without args 
    if(argc == 1){
        printf("Enter two integers: ");
        fgets(input, 26, stdin); 

        input[strlen(input)-1]='\0';

        //Validate the input length
        if(strlen(input) > MAX_BUFFER-4 || isspace(input[0])){
            puts("Error: Input is invalid or out of range.");
            return -1;
        }

        strcpy(str, input);
        
        //Check if a second token exists
        secondToken = strchr(input,' ');

        if(secondToken){
            //The first character has a space
            //We move the pointer to the next non-whitespace character
            secondToken++; 
            //Always remember strtok changes the original string.
            //Now, input and firstToken are the same.
            firstToken = strtok(input, " "); 
        }
        else{
            //There is no second token
            puts("Error: There are no two numbers.");
            return -1;
        }

        //Debugging purposes
        printTokensToDebug(firstToken, secondToken);
    }
    else if(argc == 3) //With args
    {
        argCmd = true;
        firstToken = argv[1];
        secondToken = argv[2];

        //See inside tokens if argv is used 
        printTokensToDebug(firstToken, secondToken);
        /* printf("\nfirst token:\n%s\n", firstToken); */
        /* printf("\nsecond token:\n%s\n\n", secondToken); */
    }
    else if(argc == 2)
    { //"Makes a GCF table"
        //Call the debug function from the debugger file.
        puts("GCF table not available");
        /* gcf_table(argc, argv); */
        return -1; 
    }
    else
    {
       puts("Error: Invalid argument(s)");
       return -1;

    }

    //VALIDATION
    if(isNotNumber(firstToken) || isNotNumber(secondToken)){
            puts("Error: Either first token or second token is not a number");
            return -1;
    }
    else{
        if(!((firstToken[0] == '0' && strlen(firstToken) == 1) && (secondToken[0] == '0' && strlen(secondToken) == 1)))
        {
            //change atol to stol
            char* ptr;
            twoInts[0] = strtoll(firstToken, &ptr, 10);
            twoInts[1] = strtoll(secondToken, &ptr, 10);

        }
    }

    //Turn this into a function
    while(twoInts[1] != 0)    
    {
        long long r = twoInts[0] % twoInts[1];
        twoInts[0] = twoInts[1];
        twoInts[1] = r;
    }

    printf("Greatest common divisor: %lld\n", twoInts[0]);

    return 0;
}
