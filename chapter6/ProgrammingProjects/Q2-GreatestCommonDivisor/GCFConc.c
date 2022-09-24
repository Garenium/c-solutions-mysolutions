#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdlib.h>
#include "GCFHead.h"
#include <ctype.h>

int gcf_table(char* argv[]){

   FILE* file = fopen("./logs/log.txt", "w");
   char* line = calloc(50,sizeof(char));
   printf("line (after calloc): %s\n", line);
   const char* times = ++argv[1];

    //Does the log file exist?
    if(file == NULL){
        fprintf(stderr, "file inaccessible");
        return -1;
    }
    
    //Can't be more than 5 digits
    if(!isdigit(times[0]) || strlen(times) > 5) {
        puts("More than 99999 is not suppoprted or invalid flag"); return -1;
    }else{
       char *ptr;
       unsigned short i;
       unsigned short j;

       uint64_t printTimes = strtol(times, &ptr, 10);
        printf("printTimes %"PRIu64"\n", printTimes);
        for(i = 1; i < printTimes; i++){
            for(j = 1; j < printTimes; j++){
                uint64_t gcf = calculate_gcf(i, j);
                snprintf(line, 60, "%hu GCF %hu = %"PRIu64"", i,j, gcf); //SEGFAULT
                puts(line);
                fputs(line, file);
            }
        }
     }

     free(line);

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


