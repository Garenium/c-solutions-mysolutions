#include <stdio.h>
#include <string.h>

typedef struct language_vowels{
    const char* eng;
    const char* fin;
} vowels;

int main(int argc, char* argv[]){

    puts("Counting vowels");
    puts("Author: Gareium 2023\n");

    vowels vowels_by_language = {"aeiouAEIOU", "aeiouyäöAEIOUYÖÄ"};
    const char* language_vowels = NULL;
    char input[64] = "\0";
    int vowels = 0;
    int temp_num_vowels = 0;

    /* //Ask the user what language will the text be? */
    /* char c[] = "\0"; */
    /* puts("English : 1 (default)"); */
    /* puts("Finnish : 2"); */
    /* printf("What is the language (English by default)? "); */
    /* fgets(c,1,stdin); */

    /* if(c == "\n" || c == "1"){ */
    /*     language_vowels = vowels_by_languages.eng; */ 
    /* } */
    /* else if(c == "2"){ */
    /*     language_vowels = vowels_by_languages.fin; */
    /* } */

    if(argc == 1){
        printf("Enter a sentence: ");
        fgets(input, 62, stdin);
    }
    //include file argument in the future 
    //Ex: a.out file.txt

    const char* ptr = input;

    //validate length of input
    input[strlen(input)-1] = '\0';
    if(strlen(input) > 60){
        printf("Invalid: input to long to process");
        return -1;
    }
    
    //This time I wanted to do something a bit different
    //using strspn and see how it can it be used in this
    //context instead of the usual switch case
    while(*ptr != '\0'){
        if(temp_num_vowels = strspn(ptr, vowels_by_language.eng)){
            vowels += temp_num_vowels;
            ptr = ptr + temp_num_vowels;
        }
        else{
            ptr++;
            continue;
        }
    }

    printf("Your sentence contains %d vowels.", vowels);
    printf("%s\n", ptr);

    return 0;
}
