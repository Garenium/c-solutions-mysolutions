#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 64
#define MAX_LENGTH 32

int main(int argc, char* argv[]){

    bool digit_seen[10][2] = {false};
    char input[MAX_SIZE] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    fgets(input, MAX_SIZE, stdin);

    //1. Input
    //If newline is not read, flush remaining input in stdin
    if (!strchr(input, '\n')) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        // Replace newline with null terminator
        input[strcspn(input, "\n")] = '\0';
    }

    size_t length = strlen(input);

    //2. Validating
    //validate input's length and characters
    if(!(length < MAX_LENGTH && input[0] != '0' && length == strspn(input, "0123456789"))){
       fprintf(stderr, "Invalid: input to long or has non-supported characters\n");
       return -1;
    }

    n = strtol(input, NULL, 10);

    //3. Counting
    for(int i = 0; n > 0; ++i){
        digit = n % 10;
        digit_seen[digit][0] = true; //mark it as seen
        digit_seen[digit][1] += 1; //count occurrences
        n /= 10;
    }

    /* //Printing */
    /* printf("Digit:\t"); */
    /* for(int i = 0; i < 10; ++i){ */
    /*     printf("\t%d", i); */
    /* } */

    /* printf("\nOccurances(s):"); */
    /* //count the repeated numbers */
    /* for(int i = 0; i < 10; ++i){ */
    /*     if(digit_seen[i][0]){ */
    /*         printf("\t%d", i); */
    /*     } */
    /* } */

    printf("Occurances(s):");
    //count the repeated numbers
    for(int i = 0; i < 10; ++i){
        if(digit_seen[i][0]){
            printf(" %d", i);
        }
    }


    puts("");

    /* printf("Your n is %ld\n", n); */

    /* if (n > 0) */
    /*     printf("Repeated digit\n"); */
    /* else */
    /*     printf("No repeated digit\n"); */

    return 0;
}
