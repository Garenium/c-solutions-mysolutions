#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
bool is_number(char* num){
    bool is_num = true;
    for(char* p = num; *p != '\n'; ++p){
        if(!(isdigit(*p)))        
        {
           is_num = false; 
        }
    }

    return is_num;
}

int main(int argc, char* argv[]){
    
    char str[50] = {};
    char* endPtr;
    puts("Even Square Calculator");
    puts("Garenium");
    puts("Jan 15, 2021");


    printf("Type a number (negatives are invalid): ");
    fgets(str, 42, stdin);

    /* printf("%zu\n", strlen(str)); Checking length for debugging purposes*/
    //Check if length is more than 30 digits (and \n included)
    
    /* printf("%zu\n", strlen(str)); */
    if(strlen(str) > 31){
        puts("Error: input is too long");
        return -1;
    }

    //Check if input is numeric
    if(!(is_number(str)) || str[0] == '\n'){
        puts("Error: input is invalid");
        return -1;
    }

    //Convert c-string to numeric type and 
    //prepare for output
    long int number = strtol(str,&endPtr,10);
    long int even_square = 4;
    long int x = 0;

    //Ouput
    printf("\nEven Squares: ");
    for(;;) {  
        x = x + 2;
        even_square = pow(x,2);
    if(even_square > number){

        if(x == 2)
            printf("No even squares\n");

        break;
    }
    else
        printf("\n%ld", even_square);
    }
       
    puts("");

    return 0;
}
