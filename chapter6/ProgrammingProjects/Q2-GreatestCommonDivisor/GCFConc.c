#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
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
    FILE* file = fopen("./logs/log.txt", "w");

    if(file == NULL)
    {
        fprintf(stderr, "file inaccessible");
        return -1;
    }

    enum { TEST_USHORT, TEST_UINT, TEST_ULONG, TEST_ULLONG } mode = TEST_USHORT;

    int opt = argv[1][1]; 

     switch(opt){
         case 'h': break;
         case 'd': mode = TEST_UINT; break; 
         case 'l': mode = TEST_ULONG; break;
         case 'L': mode = TEST_ULLONG; break;
         default:
         {
          fprintf(stderr, "Available flags (Without any numbers): %s [-h|-d|-l|-L]\n", argv[0]);
                puts("-h is an unsigned short integer");
                puts("-d is an unsigned integer");
                puts("-l is an unsigned long integer");
                puts("-L is an unsigned long long integer");
                return -1;
         }
     }

     const char* output;

    if(mode == TEST_USHORT){
        printf("It's unsigned short\n");

        unsigned short i;
        unsigned short j;

        /* uint8_t i; */
        /* uint8_t j; */

        for(i = 0; i < USHRT_MAX; i++){
            for(j =0 ; j < USHRT_MAX; j++){
                uint64_t gcf = calculate_gcf(i, j);
                /* sscanf(output, "%hu GCF %hu = %"PRIu64"\n", i,j, gcf); */
                /* printf(output); */
                /* fputs(file, output); */

                /* fprintf(file, "%hu GCF %hu =%"PRIu64"\n", i,j,gcf); */
                printf("%hu GCF %hu = %"PRIu64"\n", i,j,gcf);
            }
        }
        
        
    }
    else if(mode == TEST_UINT){
        printf("It's unsigned integer\n");
    }
    else if(mode == TEST_ULONG){
        printf("It's signed long\n");
    }
    else if(mode == TEST_ULLONG){
        printf("It's signed long long\n");
    }

     return 0;

}//end gcg_table()

void print_tokens(char* firstToken, char* secondToken){
    printf("first Token: %s\n", firstToken);
    printf("second Token: %s\n", secondToken);
}//end print_tokens()


uint64_t calculate_gcf(uint64_t n0, uint64_t n1){

    while(n1 != 0)    
    {
            long long r = n0 % n1;
            n0  = n1;
            n1  = r;
    }
    return n0;
}


