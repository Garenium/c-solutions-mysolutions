//Calculations tested with https://www.calculatorsoup.com/calculators/math/gcf.php
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

//Max characters in INT_MIN is 11
//11 * 2 + 1 (space between two nums) = 23
//And another four for extra space 24+4=27
#define MAX_BUFFER 27

bool isInputNumbers(char* str)
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

    printf("%d arguments(s)\n", argc);

    if(argc == 1){

        /* printf("%lld", LLONG_MAX); */
        printf("Enter two integers: ");
        fgets(input, 26, stdin); 


        input[strlen(input)-1]='\0';

        //Validate the input length
        if(strlen(input) > MAX_BUFFER-4 || isspace(input[0]))
        {
            puts("Error: Input is invalid or out of range.");
            return -1;
        }

        strcpy(str, input);
        
        //Check if a second token exists
        secondToken = strchr(input,' ');

        if(secondToken){
            secondToken++;
            //Always remember strtok changes the original string.
            //Now, input and firstToken are the same.
            firstToken = strtok(input, " "); 
        }
        else
        {
            puts("Error: There are no two numbers.");
            return -1;
        }
    }
    else if(argc == 3){

        argCmd = true;
        firstToken = argv[1];
        secondToken = argv[2];

        if(isInputNumbers(firstToken) && isInputNumbers(secondToken)){
            puts("Error: Either first token or second token is not a number");
            return -1;
        }

        //See inside tokens if argv is used 
        /* printf("first token\n%s\n", firstToken); */
        /* printf("second token\n%s\n", secondToken); */
    }
    else{
        printf("Argument command(s) are invalid");
        return -1;
    }

    //Debugging purposes
    printTokensToDebug(firstToken, secondToken);

    //Convert the tokens
    if(isInputNumbers(str) && argCmd == false){
        puts("Input is invalid. It has a non-digit character.");
        return -1; 
    }
    else{
        
        if(firstToken[0] == '0' || secondToken[0] == '0')
        {
            puts("Error: Values cannot be 0 and only base 10 numbers are allowed");
            return -1;
        }

        twoInts[0] = atol(firstToken);
        twoInts[1] = atol(secondToken);
    }

    while(twoInts[1] != 0)    
    {
        long long r = twoInts[0] % twoInts[1];
        twoInts[0] = twoInts[1];
        twoInts[1] = r;
    }

    printf("Greatest common divisor: %lld\n", twoInts[0]);

    return 0;
}
