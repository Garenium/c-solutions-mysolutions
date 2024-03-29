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
    char select_lang[8] = "\0";
    char input[64] = "\0";
    int vowels = 0;
    int temp_num_vowels = 0;

    //Ask the user what language will the text be?
    char c = '\0';
    printf("English : 1 (default)\n\t%s\n", vowels_by_language.eng);
    printf("Finnish : 2\n\t%s\n", vowels_by_language.fin);
    printf("\nWhat is the language (English by default)? ");

    fgets(select_lang, 4, stdin);
    select_lang[strlen(select_lang)-1] = '\0';
    
    if(strlen(select_lang) > 1) {
        fprintf(stderr, "Invalid selection\n");
        return -1;
    }

    c = select_lang[0];

    switch(c){
        case '1':
        language_vowels = vowels_by_language.eng; break;
        case '2':
        language_vowels = vowels_by_language.fin; break;
        default:
        language_vowels = vowels_by_language.eng; break;

    }


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
        if(temp_num_vowels = strspn(ptr, language_vowels)){
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
