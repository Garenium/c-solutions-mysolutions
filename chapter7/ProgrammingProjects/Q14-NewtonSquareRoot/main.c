#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

int main(){

    puts("Newton's square root method calc.");
    puts("Author: Garenium 2023");
    const int32_t MAX_LENGTH = 64;
    char input[MAX_LENGTH];
    double x = 0.0;
    double y = 1.0;
    double new_y = y;    
    double square_root = 0.0;
    printf("Enter a positive number: ");

    fgets(input, MAX_LENGTH, stdin);
    size_t length = strlen(input)-1;
    input[length] = '\0';

    if(!(length < MAX_LENGTH - 4 && input[0] != '0' && length == strspn(input, ".0123456789"))){
       fprintf(stderr, "Invalid: input to long or has non-supported characters\n");
       return -1;
    }

    char* temp_ptr = input;
    char** temp_double_ptr = &temp_ptr;
    x = strtod(input,temp_double_ptr);
     
    printf("x is %lf\n", x);

    double fabs_diff = 0.0;
    do{
        double x_div_y = x/y;
        double avg = (y + x_div_y)/2;
        
        puts("");
        printf("x: %lf\n", x);
        printf("y: %lf\n", y);
        printf("x/y: %lf\n", x_div_y);
        printf("Average of y and x/y: %lf\n", avg);
        puts("");
        
        new_y = x_div_y;
        y = avg;

    }while(fabs(y - new_y) > 0.00001*y);


    return 0;
}
