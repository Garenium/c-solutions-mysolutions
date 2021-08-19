#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    char* endPtr1;
    char* endPtr2;
    int hours;
    int minutes;
    char input[10];
    bool invalid = true;
    int c;

    puts("Convert Military Time to 12 Hour Time");
    puts("Author: Garenium");
    puts("Date: Jun 5, 2021");

    //A while loop to validate the length of the strength.
    while(invalid){

        printf("Enter a 24-hour time: ");
        fgets(input, 8, stdin);

        if(strlen(input) < 7)
            input[strlen(input)-1]='\0';
        else if(strlen(input) == 7 && input[strlen(input)-1] == '\n')
            input[strlen(input)-1]='\0';
        else if(strlen(input) == 7)
            while(c = getchar() != '\n' && c != EOF);
                
        
        //Check if user input is too long or too short 
        if(strlen(input) > 5 || strlen(input) < 5){
            puts("Error: Input is too long or short. [Line 38]");
            invalid = true;      
        }
        else if(input[2] != ':'){ //Check if there is a colon in the middle (00:00)
            puts("Error: Input is not properly formatted. Please use the 00:00 format. [Line 42]");
            invalid = true;
        }
        else{
            //Catch the first and the last two characters and convert them to an int
            char* hours_c = strtok(input, ":");
            char* minutes_c = strtok(NULL, ":");

            int hours = strtol(hours_c, &endPtr1, 10);
            int minutes = strtol(minutes_c, &endPtr2, 10);

            //Make sure if the minutes and hours are all numeric characters
            if(strcmp(endPtr1, "") || strcmp(endPtr2, ""))
            {
                puts("Error: Non-numeric input is not allowed. Please use the 00:00 format. [Line 56]");
                invalid = true;
            }
            else if((hours < 0 ||  hours >= 24))//Make sure if they're all in range
            {
                puts("Error: Time is out of range. Please use the 00:00 format. [Line 61]");
                invalid = true;
            }
            else if(minutes < 0 ||  minutes > 60)
            {
                puts("Error: Time is out of range. Please use the 00:00 format. [Line 66]");
                invalid = true;

            }
            else{
                bool isPM = false;//Start converting 24 to 12
                if(hours > 12 || hours == 0)  {
                    if(hours == 0)
                        hours = 12;
                    else{
                    hours = hours - 12;
                    isPM = true;
                    }
                }

                printf("%02d:%02d ", hours, minutes);
                printf("%s\n", (isPM == false) ? "AM" : "PM");
              invalid = false;
            }
        }
    }
    

    
       return 0;
}
