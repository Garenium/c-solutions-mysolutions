#include <stdio.h>

int main(int argc, char* argv[]) {

    char c;
    double length = 0.0;
    int wordCount = 1;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n') {
        if (c == ' ')
            wordCount++;
        else 
            length++;

        if(length > 32.0f){
            puts("The sentence is too long. Exiting the program");
            return -1;
        }
    }

    printf("Average word length: %.1f\n", length / wordCount);
    return 0;
}
