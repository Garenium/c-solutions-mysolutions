#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    bool isInt = false;
    char n[4];
    size_t i = 0;
    int c;
    while (!isInt)
    {
        bool tooLong = false;
        printf("Enter a two digit number: ");
        fgets(n, 4, stdin);


        if(n[strlen(n)-1] == '\n')
        {
            //printf("%zu", strlen(n)); Debugging purposes
            n[strlen(n) - 1] = '\0';
            ungetc('\n', stdin);
        }       

        //Condition 1: Validate the length of the c-string 
        if (strlen(n) == 2)
        {
            //Condition 2: Validate the content of the c-string
            if (isdigit(n[0]) && isdigit(n[1]))
            {
                isInt = true;
            }
            else 
            {
                puts("Error: Invalid input");
                while ((c = getchar()) != EOF &&   c!= '\n') {};
            }
        }
        else 
        {
            //printf("%zu", strlen(n)); Debugging purposes
            puts("Error: please type only two digits");
            while ((c = getchar()) != EOF &&   c!= '\n') {};
        }
    }
    //If validated, print backwards
    for (int i = strlen(n)-1; i >= 0; --i)
    {
        printf("%c", n[i]);
    }
    puts("");
    return 0;
}
