//Calculations tested with https://www.calculatorsoup.com/calculators/math/gcf.php
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "GCFHead.h"

//The magic number is 27
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

//Works for strings (tokens) parsed with the a white-space delimiter
bool is_not_number(char* str)
{
    bool condition = false;
    int negException = 0;
    int spaceException = 0;
    for(size_t i = 0; i < strlen(str); ++i){

        if(str[i] == '0' && i == 0){
             condition = true;
             break;
        }
        else if(str[i] == '-') {
            /* i++; */
            /* negException++; */
            /* if(negException > 1){ */
            /*     condition = true; */
            /*     break; */
            /* } */

                condition = true;
                break;
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
}//end is_not_number()


int main(int argc, char* argv[])
{
    //Max no. of digits in MAX_IN is 10, since there are two integers involved and negative numbers are valid, a bump up to 27 is appropriate.
    char input[MAX_BUFFER];   
    char str[MAX_BUFFER];
    uint64_t twoInts[2]; 
    int count = 0;
    char *firstToken;
    char *secondToken;
    char *endPtr; 
    bool argCmd = false;

    //Debugging purposes
    /* printf("%d argument(s)\n", argc); */
    /* printf("\nargc: %d\nargv[1]: %s\n", argc, argv[1]);      //may segfault */
    /* printf("argv[1][0]: %d (%c)\n", argv[1][0], argv[1][0]); //may segfault */
    /* printf("sizeof(argv[1]): %zu\n", sizeof(argv[1]));       //may segfault */
    /* printf("ASCII (-): %d (%c)\n\n", '-', '-'); */

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
        print_tokens(firstToken, secondToken);
    }
    else if(argc == 2 && argv[1][0] == '-' && strlen(argv[1]) == 2)
    { //"Makes a GCF table"
        //Call the debug function from the debugger file.
        return gcf_table(argc, argv);
    }
    else if(argc == 3) //With args
    {
        argCmd = true;
        firstToken = argv[1];
        secondToken = argv[2];

        //See inside tokens if argv is used 
        print_tokens(firstToken, secondToken);
    }
    else
    {
       puts("Error: Invalid argument(s)");
       return -1;
    }


    //VALIDATION
    if(is_not_number(firstToken) || is_not_number(secondToken)){
            puts("Error: Either first token or second token is a negative or not a number");
            return -1;
    }
    else{
            char* ptr;
            twoInts[0] = strtoll(firstToken, &ptr, 10);
            twoInts[1] = strtoll(secondToken, &ptr, 10);
    }

    uint64_t GCF = calculate_gcf(twoInts[0], twoInts[1]);

    printf("Greatest common divisor: %"PRIu64"\n", GCF);

    return 0;

}//end main()
