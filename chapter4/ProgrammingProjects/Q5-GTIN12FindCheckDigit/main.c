#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
int main(int argc, int* argv[])
{
    typedef uint16_t uint;

    char upc[15];
    int c;
    //bool valid = true;

    uint firstSum = 0;
    uint secondSum = 0;
    uint checkDigit = 0;

    puts("Check digit calculator for GTIN-12");
    puts("Author: Garenium");
    puts("Date: Jun 5, 2021");

    printf("Enter the first 11 digits of a UPC (GTIN-12): ");
    fgets(upc, 14, stdin);
    //while((c = getchar()) != '\n' && c != EOF); //flushing the buffer
    upc[strlen(upc)-1] = '\0';
    
    printf("upc = %s\n", upc); //Debugging purposes

    if(strlen(upc) < 11 || strlen(upc) > 11)
    {
        puts("Error: less or more than specified digits (11) [line 32]");
        return -1;
    }

    size_t i;
    for(i = 0; i < strlen(upc); ++i)
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
    /*printf("firstSum = %u\n", firstSum);
    printf("secondSum = %u\n", secondSum);*/

    
    checkDigit = ((secondSum*3+firstSum)-1);
    checkDigit = checkDigit % 10;
    checkDigit = 9 - checkDigit;
    printf("Check digit: %u\n", checkDigit);
    return 0;
}
