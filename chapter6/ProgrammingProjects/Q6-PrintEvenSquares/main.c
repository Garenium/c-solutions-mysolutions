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
    puts("The following program prints all even squares");
    
    fgets(str, 42, stdin);

    /* printf("%zu\n", strlen(str)); */
    if(strlen(str) > 31){
        puts("Error: input is too long");
        return -1;
    }

    if(!(is_number(str)) || str[0] == '\n'){
        puts("Error: input is invalid");
        return -1;
    }

    puts("\nEven Squares:");
    long int number = strtol(str,&endPtr,10);
    long int even_square = 2;
    long int x = 0;

    while(even_square < number){  
        x = x + 2;
        even_square = pow(x,2);
        printf("%ld\n", even_square);
    }


    return 0;
}
