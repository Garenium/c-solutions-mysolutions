#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 64

void printIntro(){
    const char* intro = 
        "Check digit calculator UPC-A and EAN-13 barcodes\n"
        "Author: Garen Ikezian\n"
        "Date: jun. 5, 2021\n"
        "For confirmation: see https://www.gs1.org/services/check-digit-calculator\n";
    
    puts(intro);
}

void run_gsi(const int max_digits, const int mode, const char* mode_str){

	typedef uint16_t uint;
	char input_number[MAX_SIZE];
    size_t input_number_len = 0;
    char* endPtr;
    bool valid_input = false;
	uint odd_sum = 0;
	uint even_sum = 0;
	uint check_digit = 0;

    do{
        printf("Enter the first %d digits of %s: ", max_digits, mode_str);
        fgets(input_number, sizeof(input_number), stdin);
        input_number_len = strlen(input_number);
        input_number[input_number_len-1] = '\0';

        if(input_number_len < max_digits && input_number_len > max_digits){
            puts("Error: Input needs to be %d digits long\n");
        }
        
        strtol(input_number, &endPtr, 10);
        if(*endPtr != '\0')
            puts("Invalid input. Please try again.\n");
        else
            valid_input = true;


    }while(!valid_input);

    //Start calculating
    //1. Start adding
    for(size_t i = 0; i < input_number_len; ++i){
        if(i % 2 == 0)
            odd_sum += input_number[i] - '0';
        else if(i % 2 == 1)
            even_sum += input_number[i] - '0';
    }


    //2. Use the algorithms
    switch(mode){
        case 0:{
                    check_digit = ((even_sum*3)+odd_sum)-1;
                    check_digit = check_digit % 10;
                    check_digit = 9 - check_digit;
                    printf("Check digit: %u\n", check_digit);
                    break;
               }
        
        case 1:{
                    check_digit = ((odd_sum*3)+even_sum)-1;
                    check_digit = check_digit % 10;
                    check_digit = 9 - check_digit;
                    printf("Check digit: %u\n", check_digit);

               }
    }


    return;
}

int main(int argc, char* argv[]){

    char str[MAX_SIZE] = "\0";
    bool valid_input = false; 
    enum {UPC_A, EAN_13} mode = UPC_A;

    if(argc == 1){
        puts("Choose an option:");
        puts("1. UPC-A (GTN-12)\n2. EAN (GTN-13)\n");

            do{
                printf("Input: ");
                if(!fgets(str, sizeof(str), stdin))
                    continue;

                valid_input = (strlen(str)-1 == 1 && isdigit((uint16_t)str[0]));

                char choice = str[0];
                switch(choice) {
                   case '1':{
                               mode = UPC_A; 
                               break;
                            }
                   case '2':{
                               mode = EAN_13;
                               break;
                            }
                   default:
                           valid_input = false; break;
                }

                if(!valid_input){
                    puts("Invalid Input.");
                }

             }while(!valid_input);
        }
    else{
        int opt;
            while((opt = getopt(argc, argv, "hue")) != -1){
                switch(opt){
                    case 'h':
                        printIntro(); 
                        return -1;
                    case 'u':
                        mode = UPC_A;
                        break;
                    case 'e':
                        mode = EAN_13;
                        break;
                    default:
                        printIntro();
                        return -1;
                }
            }
    }


    switch(mode){
	    case UPC_A:{
            printf("You have selected %s.\n", "UPC-A");
		    run_gsi(11, mode, "UPC-A"); break;
		       }
	    case EAN_13:{
            printf("You have selected %s.\n", "EAN-13");
		    run_gsi(12, mode, "EAN-13"); break;
		 	}
    }

    return 0;
}
