#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

typedef long long dataType;

dataType countDigits(dataType n) {

    dataType count = 0;
        while(n != 0){
       n = n / 10;
       ++count; 
    }

    return count;
 }


int main(int argc, char* argv[])
{
    
    char input[30]; //long long has 19 digits
    printf("Enter a number: "); //prompt the user
    fgets(input, 25, stdin); 

    if(strlen(input) <= 22)//!!Check/Debug 
        input[strlen(input)-1]='\0';

    char* endPtr;

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

    if(num == LLONG_MAX || num == LLONG_MIN)
    {
       puts("Input out of max/min range [Line 45]");
       return -1;
    }
    
     printf("The number %lld has %lld digits.\n", num, countDigits(num)); 
    
    //printf("The number %s has %zu digits.\n", input, strlen(input));
    return 0;
}
