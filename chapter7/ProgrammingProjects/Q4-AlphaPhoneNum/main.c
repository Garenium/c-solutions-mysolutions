#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, int* argv[]){
    
    const int MAX_LENGTH = 32;
    char input[MAX_LENGTH];
    char* ptr = NULL;
    printf("Enter phone number: ");

    fgets(input, MAX_LENGTH-2, stdin);

    input[strlen(input)-1] = '\0';

    //Debugging
    /* printf("%s\n", input); */
    /* printf("%zu\n",strlen(input)); */

    //Stop program if input is too long to process
    if(strlen(input) > 25){
        printf("Invalid: input is too long to process. It cannot accept more than 25 characters.\n");
        return -1;
    }

    //Loop the input char by char. Print the their respective number one by one
    for(int i = 0; i < strlen(input); i++)
    {
        if(isalpha(input[i])){
            char letter = toupper(input[i]);
            switch (letter) {
            case 'A': case 'B': case 'C':
                putchar('2');
                break;
            case 'D': case 'E': case 'F':
                putchar('3');
                break;
            case 'G': case 'H': case 'I':
                putchar('4');
                break;
            case 'J': case 'K': case 'L':
                putchar('5');
                break;
            case 'M': case 'N': case 'O':
                putchar('6');
                break;
            case 'P': case 'R': case 'S':
                putchar('7');
                break;
            case 'T': case 'U': case 'V':
                putchar('8');
                break;
            case 'W': case 'X': case 'Y':
                putchar('9');
                break;
            }
        }
        else{
            printf("%c",input[i]);
        }
    }

        puts("");

    return 0;
}
