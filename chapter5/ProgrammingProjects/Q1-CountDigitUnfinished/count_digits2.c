#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef long long dataType;

int main(int argc, char* argv[])
{
    
    char input[10]; //long long has 19 digits
    printf("Enter a number: "); //prompt the user
    fgets(input, 5, stdin); 
    char* endPtr;

    //input[strlen(input)-1]='\0';

    //Use regex instead...
    dataType num = strtoll(input, &endPtr, 10);

    //Check if there is a non-numeric substring in str
    if(strcmp(endPtr, "") || (input[0] == '0' && strlen(input) > 1) || (strlen(input) == 0 && input[0] == '\0'))
    {
       puts("Invalid input [Line 39]");
       return -1;
    }
    /*else if(strlen(input) == 0 && input[0] == '\0')
    {
       puts("Invalid input [Line 39]");
       return -1;
    }*/

    /* if(num == LLONG_MAX || num == LLONG_MIN) */
    /* { */
    /*    puts("Input out of max/min range [Line 45]"); */
    /*    return -1; */
    /* } */
    
    /*  printf("The number %lld has %lld digits.\n", num, countDigits(num)); */ 
    
    printf("The number %s has %zu digits.\n", input, strlen(input));
    return 0;
}
