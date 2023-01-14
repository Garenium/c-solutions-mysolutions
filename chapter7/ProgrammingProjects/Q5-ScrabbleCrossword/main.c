#include <stdio.h>
#include <ctype.h>
int main(int argc, int* argv[]){

    //Scrabble doesn't accept numerical characters. Only alphabetical letters.
    //loop through each letter while adding the value 
    char letter = '\0';
    int scrabble_value = 0;
    printf("Enter a word: ");
    while((letter = getchar()) != '\n'){

        switch(toupper(letter)){
            case 'A': case 'E': case 'I': case 'L': case 'N': 
            case 'O': case 'R': case 'S': case 'T': case 'U':
                scrabble_value += 1;
                break;
            case 'D': case 'G':
                scrabble_value += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                scrabble_value += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                scrabble_value += 4;
                break;
            case 'K':
                scrabble_value += 5;
                break;
            case 'J': case 'X':
                scrabble_value += 8;
                break;
            case 'Q': case 'Z':
                scrabble_value += 10;
                break;
            default:
                break;
        }
    }

    //debug
    /* printf("letter: %c\n", letter); */
    printf("Scrabble value: %d\n", scrabble_value);

    return 0;
}
