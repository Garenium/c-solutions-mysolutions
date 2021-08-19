#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int main(){
    

    char input[50]; //Buffer for user input
    int numbers[4]; //Array to store numbers
    size_t i = 0;  //iterator to keep track on array length
    char* tok; //Token from str
    int checkNumber = 0; //Verified token (numeric)
    char* endPtr; //To check if there are any non-numeric characters (via strtol)
    int maxNumber;
    int minNumber;


    printf("Enter four integers: ");
    fgets(input, 49 ,stdin);

    printf("Input: %s\n", input); //For Debugging purposes

    input[strlen(input)-1]='\0';

    tok = strtok(input, " ");
    while(tok != NULL){

       if(i > 0){
          //Take the token
          tok = strtok(NULL, " ");
          if(tok == NULL)
              break;
       }

       checkNumber = strtol(tok, &endPtr, 10);
       //Check if it's a number
        if(strcmp(endPtr, "")){

            puts("Error: Only numeric inputs are allowed.");
            return -1;
        }

       //Assign the number to the array
       ++i;
       if(i > 4){
           puts("Error: Only four numbers are allowed");
           return -1;
       }

       //append the number to the array
       numbers[i-1]= checkNumber;
    }


    if(i == 4)
    {
        minNumber = numbers[0];
        maxNumber = numbers[0];
        int sum = 0;
        for(size_t j = 0; j < 4; j++){
            if(numbers[j] == INT_MAX || numbers[j] == INT_MIN){
                puts("One of the numbers are out of bounds.");
                return -1;
            }
            else{
                if(numbers[j] > maxNumber)
                    maxNumber = numbers[j];

                if(numbers[j] < minNumber)
                    minNumber = numbers[j];

                sum += numbers[j];
            }
        }
        printf("Largest: %d\nSmallest: %d\n", maxNumber, minNumber);
        printf("Sum: %d\n", sum);
    }
    else
    {
        puts("Only four numbers are allowed.");
        return -1;
    }

    return 0;
}

    /* char test[64] = "This is a test"; */
    /* printf("%s\n", test); */

    /* char beatles[64] = "John, Paul, Ringo, George"; */

    
    /* int it = 0; */
    
    
    /* char* token = strtok(beatles, "-"); */
    /* printf("%d [%p] --- %s\n", it, beatles, beatles); */

    /*printf("%s\n", beatles);
    char* token = strtok(beatles, " ");
    printf("%s\n", beatles);
    printf("%d [%p] --- %s\n", it, beatles, beatles);

    token = strtok(NULL, " ");
    printf("%d [%p] --- %s\n", it, beatles, token);
    
    printf("%s\n", beatles);*/


