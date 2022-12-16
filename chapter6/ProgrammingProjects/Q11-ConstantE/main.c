#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    
    puts("Finding Euler's e...");
    puts("Garenium");

    double approx_e = 1;
    char input[50] = "\0";
    printf("Type a number [n >= 0]: ");
    fgets(input,47,stdin);

    //changing last character \n to \0
    //to avoid ambiguity in length
    input[strlen(input)-1] = '\0';

    //set a pointer for the functions strspn and strlen
    const char* ptr = input;

    //check the length
    if(strlen(ptr) > 45){
        printf("Invalid: Input is too long");
            return -1;

    } //No negative nums, no letters or symbols. Count only digits
    else if(strspn(ptr, "012345679") == strlen(ptr)){ 
        char *temp;
        //Convert type c-string to int
        int n = strtol(ptr,&temp,10);
        
        //Debugging input
        /* printf("n is %d\n", n); */

        //May use another variable fact below
        double fact = 1;
        for(double i = 1; i <= n; ++i){
            
            double j = i;

            if(i != 1){
                for(double j = i; j > 1.0; --j){
                    fact = fact * (j - 1.0);
                }
            }
            
            approx_e += 1.0/fact;
        }

        printf("e approx.is %lf\n", approx_e);

    }

    return 0;
}
