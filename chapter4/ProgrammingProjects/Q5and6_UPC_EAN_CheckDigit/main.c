#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 64
#define MAX_INPUT 32

void printIntro(){
    const char* intro = 
        "Check digit calculator UPC-A and EAN-13 barcodes\n"
        "Author: Garen Ikezian\n"
        "Date: jun. 5, 2021\n"
        "For confirmation: see https://www.gs1.org/services/check-digit-calculator\n";
    
    puts(intro);
}

int main(int argc, char* argv[]){

    char str[MAX_SIZE] = "\0";
    bool validInput = false;
    enum {UPC_A, EAN_13} mode = UPC_A;

    puts("Choose an option:");
    puts("1. UPC-A (GTN-12)\n2. EAN (GTN-13)\n");

    printf("Input: ");

    while(!validInput){
        fgets(str, MAX_SIZE-2, stdin);
        printf("STRLEN: %zu\n", strlen(str));

        if(strlen(str)-1 == 1 && isdigit(str[0])) {
           puts("hello");
           char choice = str[0];
           switch(choice) {
               case '1':
                   mode = UPC_A; validInput = true; break;
               case '2':
                   mode = EAN_13; validInput = true; break;
               default:
                   break;
           }
        }
        else{
            puts("Please try again");
            printf("Input: ");
        }
    }

    printf("mode %d", mode);

    return 0;
}
