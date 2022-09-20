#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "GCFHead.h"

int gcf_table(int argc, char* argv[]){
   /*
     *
     * By the time I was writing this, I want to add a "debugger" built in 
     * the source code so that I check if all the GCD calculations are valid.
     * I've tried writing a bash code but it is extremely slow and not ideal.
     * So I needed to make a do-while loop to loop through like this
     * (INT_MIN + x) % (INT_MIN + y)
     * Something similar to
     * 0 mod 0
     * 0 mod 1
     * 0 mod 2
     * 0 mod 3
     * ...   ...
     * 1 mod 0
     * 1 mod 1
     * 1 mod 2
     * etc.
     * But we will be using the range INT_MIN to INT_MAX instead.
     * INT_MIN mod INT_MIN + x      (where x starts at 0 and then appended by one after each iteration)
     * 
     * IMPORTANT!!!
     * **Calculator Soup (The website) does not accept an operand 
     * more than 10,000,000,000,000**
     *
     */

    /*
     *
     * This is how I can 
            LLONG_MAX = 18,446,744,073,709,551,615

            LONG_MAX = 9,223,372,036,854,775,807

            MAX RANGE = LONG_MAX * 2 - 1 = 18,446,744,073,709,551,615 - 5

            18,446,744,073,709,551,610 max times

     * */

    enum { TEST_SHORT, TEST_INT, TEST_LONG, TEST_LLONG } mode = TEST_SHORT;

    int opt = argv[1][1]; 

     switch(opt){
         case 'h': break;
         case 'd': mode = TEST_INT; break; 
         case 'l': mode = TEST_LONG; break;
         case 'L': mode = TEST_LLONG; break;
         default:
         {
                fprintf(stderr, "Usage: %s [-h] [-d] [-l] [-L]\n", argv[0]);
                puts("-h is a signed short integer");
                puts("-d is a signed integer");
                puts("-l is a long integern");
                puts("-L is a long long integer");
                return -1;
         }
     }

    if(mode == TEST_SHORT){
        printf("It's signed integer\n");
        
    }
    else if(mode == TEST_INT){
        printf("It's signed integer\n");
    }
    else if(mode == TEST_LONG){
        printf("It's signed long\n");
    }
    else if(mode == TEST_LLONG){
        printf("It's signed long long\n");
    }

     return 0;

}//end gcg_table()

void print_tokens(char* firstToken, char* secondToken){
    printf("first Token: %s\n", firstToken);
    printf("second Token: %s\n", secondToken);
}//end print_tokens()


long long calculate_gcf(long long n0, long long n1){

    while(n1 != 0)    
    {
            long long r = n0 % n1;
            n0  = n1;
            n1  = r;
    }
    return n0;
}


