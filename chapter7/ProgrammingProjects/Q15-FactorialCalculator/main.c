#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, int* argv[]){

    char input[64] = "\0";
    void *ans = '\0';

    printf("Enter a positive number: ");
    fgets(input, 62, stdin);

    input[strlen(input)-1] = '\0';

    if(strlen(input) > 60){
        puts("Error: input is too long. The program only accepts 60 characters long");
        return -1;
    }
    else if(input[0] == '-'){
        puts("Error: negative numbers are not accepted");
        return -1;
    }

    for(size_t i = 0 ; input[i] != '\0'; ++i){
        if(isalpha(input[i])){
        puts("Input is not a number. Exiting the program...");
        return -1;
     }
    }

    printf("Input is %s\n", input);
    puts("");

    char* endptr = NULL;
    if(strspn(input, "0123456789\n") != strlen(input)){
        puts("Found decimal point");

        long double floating_input = strtold(input, &endptr);
        long double floating_fact = 1.0;

        for(long double i = floating_input; i > 1.0; i--){
                floating_fact *= i; 
        }

        printf("FLoat: %20f\n",           (float)floating_fact);
        printf("Double: %20lf\n",         (double)floating_fact);
        printf("Long double; %20Lf\n",    (long double)floating_fact);
        
    }
    else{

        long long integral_input = strtoll(input, &endptr, 10);
        long long integral_fact = 1;

        for(long long i = integral_input; i > 1; i--){
                integral_fact *= i; 
        }

        printf("Short: %24.hu\n",       (short)integral_fact);
        printf("Long: %25.ld\n",        (long)integral_fact);
        printf("Long long: %20.Ld\n",   (long long)integral_fact);

    }

    return 0;
}
