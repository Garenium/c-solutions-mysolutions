#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int main(){
    char input[50]; //Buffer for user input
    long long numbers[4]; //Array to store numbers
    size_t i = 0;  //iterator to keep track on array length
    char* tok; //Token from str
    int checkNumber = 0; //Verified token (numeric)
    char* endPtr; //To check if there are any non-numeric characters (via strtol)
    int maxNumber;
    int minNumber;

    printf("%llu\n", LLONG_MAX); 

    printf("Enter four integers: ");
    fgets(input, 49 ,stdin);

    printf("Input: %s\n", input); //For Debugging purposes

    input[strlen(input)-1]='\0';

    //Breaking into tokens and appending them to the numbers array
    tok = strtok(input, " ");
    while(tok != NULL){

       if(i > 0){
          //Take the token
          tok = strtok(NULL, " ");
          if(tok == NULL)
              break;
       }

       checkNumber = strtoll(tok, &endPtr, 10);
       //Check if it's a number
        if(strcmp(endPtr, "")){

            puts("Error: Only numeric/whole number inputs are allowed.");
            return -1;
        }

        if(strlen(input) >= 10){
            puts("Error: One number is too long to process.");
            return -1;
        }

       //Assign the number to the array
       /* ++i; */
       if(i > 4){
           puts("Error: Only four numbers are allowed");
           return -1;
       }

       //append the number to the array
       numbers[i++]= checkNumber;
    }


    if(i == 4)
    {
        minNumber = numbers[0];
        maxNumber = numbers[0];
        long long int sum = 0;
        for(size_t j = 0; j < 4; j++){
                if(numbers[j] > maxNumber)
                    maxNumber = numbers[j];

                if(numbers[j] < minNumber)
                    minNumber = numbers[j];

                sum += numbers[j];
        }
        printf("Largest: %d\nSmallest: %d\n", maxNumber, minNumber);
        printf("Sum: %lld\n", sum);
    }
    else
    {
        puts("Only four numbers are allowed.");
        return -1;
    }

    return 0;
}
