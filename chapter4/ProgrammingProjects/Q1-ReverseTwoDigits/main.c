#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_SIZE 4 //2 digits + '\n' + '\0'
            

//Helper function to clear extra chars from stdin
void clearInputBuffer(void)
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF) {}
}

int main(void)
{
    char input[INPUT_SIZE];
    int n = -1;
    bool isValid = false;
    int c;

    while (!isValid)
    {
        printf("Enter a two digit number: ");
        
        if(fgets(input, sizeof(input), stdin) == NULL){
            puts("Error reading input");
            return 1;
        }

        //Remove trailing newline. Otherwise, flush leftover input
        size_t len = strlen(input);
        if(len > 0 && input[len -1] == '\n')
        {
            input[len - 1] = '\0';
        }       
        else{
            clearInputBuffer();
        }

        //Condition 1: Validate the length of the c-string 
        //Condition 2: Validate the content of the c-string
        if (strlen(input) == 2 && isdigit((unsigned char)input[0]) && isdigit((unsigned)input[0])) {        
            isValid = true;
        }
        else 
        {
            puts("Error: please type only two digits");
        }
    }

    //Based on the "hint" part in the book.
    n = ((input[1]-'0')*10) + (input[0]-'0');
    printf("%d%d",n/10, n%10);
    puts("");
    return 0;
}
