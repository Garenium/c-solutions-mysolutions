#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


void printIntro(){

    const char* intro = 
        "Light Decimal to Octal Converter\n"
        "Author: Garen Ikezian\n"
        "Date: Oct. 22, 2025\n"
        "Usage: lightd2oconv [-h] <decimal_number>\n";

    printf("%s", intro); 
}

bool validateInput(int* x ,int argc, char* argv[]){

    const int MAX_SIZE = 10;
    char str[MAX_SIZE];
    char* endPtr;


    //Two conditions for bashscript use or without
    if(argc >= 2)
    {
        *x = strtol(argv[1], &endPtr, 10);

        //Debugging purposes
        /* printf("What is *x:  %d\n", *x); */
        /* printf("ENDPTR %s\n", endPtr); */
        /* printf("argv[1] = %d\n", *x); */

        //*endPtr == '\0' means all chars in argv[1] were numeric
        if(*endPtr == '\0')
            return true;
        else
            return false;

    }
    else{
        printf("Enter a number between 0 and 32767: ");
        fgets(str, MAX_SIZE, stdin);
        str[strlen(str)-1]='\0';
        
        *x = strtol(str, &endPtr, 10);

        //endPtr != '\0' means there were non-numeric non-numeric characters.
        if(str[0] == '0' || str[0] == '\0' || *endPtr != '\0'){
            return false; 
        } 
        else
        {
            return true;
        }
    } 
}


int main(int argc, char* argv[])
{
    int x = 0;
    bool validInput = false;
    int opt;

    if(argc > 2){
        printIntro();
        return -1;
    }
    else{
        while((opt = getopt(argc, argv, "h")) != -1){
            switch (opt){
                case 'h':
                    printIntro(); return -1;
            }
        }
    }

    
    do{
        validInput = validateInput(&x, argc, argv);

        //If it's a number, validate the range
        if(validInput){
            if(x < 0 || x > 32767){
                puts("Error: Out of range");
                validInput = false;
            }
        }
        else{
            puts("Error: Input is not a number");
            if(argc >= 2)
                return -1;
        }
 
    } while (!validInput);
   
    /* printf("Number: %d\n", x); //Debugging to check the content of x */
    printf("In octal, your number is: 0%o\n", x);

    return 0;
}
