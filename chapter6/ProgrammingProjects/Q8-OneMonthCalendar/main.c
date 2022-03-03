#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int validateNoDays(char* input);

int validateStartDay(char* input);

int main(int argc, char* argv[]){

    char input[5] = {};
    int daysInMonth = -1;
    int startingDay = -1;
    bool invalidInput = false;

    if(argc == 1){
        printf("Enter number of days in month: ");
        fgets(input, 6, stdin ); //inputting days in month
        
        input[strlen(input)-1] = '\0';
        daysInMonth = validateNoDays(input);
        if(daysInMonth == -1) {puts("Error: Invalid input"); return -1;}  
        
        //Validate the starting day of the week input
        printf("Enter starting day of the week (1=Sun, 7=Sat): ");
        fgets(input, 6, stdin);

        input[strlen(input)-1] = '\0';
        startingDay = validateStartDay(input);
        if(startingDay == -1) {puts("Error: Invalid input"); return -1;}

    }
    else if(argc == 3){
        /* printf("%s\n", argv[1]); */
        /* printf("%s\n", argv[2]); */

        daysInMonth = validateNoDays(argv[1]);
        printf("daysInMonth: %d\n", daysInMonth);
        if(daysInMonth == -1) {puts("Error: Invalid input"); return -1;}  

        input[strlen(input)-1] = '\0';
        startingDay = validateStartDay(argv[2]);
        printf("startingDay: %d\n\n", startingDay);
        if(startingDay == -1) {puts("Error: Invalid input"); return -1;}

        if(daysInMonth == -1 || startingDay == -1){
            puts("Error: Invalid input");
            return -1;
        }
    }
    else{
        puts("Error: Invalid arguments");
        return -1;
    }
    
    /*Print any leading whitespace characters*/
    printf("\n");

    int i;
    for(i = 1; i < startingDay; ++i )
       printf("   ");

    for(i = 1; i <= daysInMonth; ++i){
        printf("%3d", i);
        if((startingDay + i - 1) % 7 == 0)
            printf("\n");
    }
    
    printf("\n");
    
    return 0;
}

int validateNoDays(char* input){

    int daysInMonth = -1;

    //Validate number of days input
    if(strlen(input) == 2 || strlen(input) == 3 && input[strlen(input)-1] == '\n'){
        if((input[0] != '0') && (input[0] == '2' || input[0] == '3'))
        {
           //check if they're all digits
           char* ptr = input;

           ++ptr; //point at ones digit
           daysInMonth = (int)(*ptr-'0');

           --ptr; //point at tens digit
           daysInMonth += (int)(*input-'0')*10;

           if(!(daysInMonth >= 28 && daysInMonth <= 31))
           {
               daysInMonth = -1;
               puts("Error: Invalid number of days!");
           }
        }
    }

    /* if(daysInMonth == -1) */
    /*     puts("Error: Invalid input"); */

    return daysInMonth;
}

int validateStartDay(char* input){

    int startingDay = -1;
    if(strlen(input) == 1 || strlen(input) == 2 && input[strlen(input)-1] == '\n'){

        if((*input >= '1' && *input <= '7')){
            /* puts("Inside"); */
            startingDay = (int)*input-'0';      
        }
    }

    /* if(startingDay == -1) */
    /*     puts("Error: invalid input"); */

    return startingDay;
}


