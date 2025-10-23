#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 16
#define MAX_INPUT 12

void printIntro(){
    const char* intro = 
        "Check digit calculator for EAN-13 (GTIN-13)\n"
        "Author: Garen Ikezian\n"
        "Date: Jun. 5, 2021\n"
        "For confirmation: see https://www.gs1.org/services/check-digit-calculator\n";

    printf("%s\n", intro);
}

int main(int argc, int* argv[])
{
    typedef uint16_t uint;

    char upc[MAX_SIZE];
    int c;
    //bool valid = true;

    uint firstSum = 0;
    uint secondSum = 0;
    uint checkDigit = 0;

    printIntro();

    printf("Enter the first 12 digits of an EAN: ");
    fgets(upc, MAX_SIZE-1, stdin);
    //while((c = getchar()) != '\n' && c != EOF); //flushing the buffer
    upc[strlen(upc)-1] = '\0';
    
    //Debugging purposes
    //printf("upc = %s\n", upc); 

    if(strlen(upc) < MAX_INPUT || strlen(upc) > MAX_INPUT)
    {
        puts("Error: less or more than specified digits (12)");
        return -1;
    }

    for(size_t i = 0; i < strlen(upc); ++i)
    {
        if(!(isdigit(upc[i]))){
            puts("Error: invalid input [line: 40]");
            return -1;
        }

        if(i % 2 != 0) //add up all odd index elements
          firstSum += (upc[i])-'0';
        else if(i % 2 == 0) //add up all even index elements
          secondSum += (upc[i])-'0';
    }

    //Debugging purposes 
    printf("firstSum = %u\n", firstSum);
    printf("secondSum = %u\n", secondSum);

    checkDigit = ((firstSum*3)+secondSum)-1;
    checkDigit = checkDigit % 10;
    checkDigit = 9 - checkDigit;
    printf("Check digit: %u\n", checkDigit);
    return 0;
}
