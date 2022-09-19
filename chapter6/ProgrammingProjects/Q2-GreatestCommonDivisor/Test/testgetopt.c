#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv){

    int opt;
    while((opt = getopt(argc, argv, "hdlL")) != -1){
            switch(opt){
                case 'h': 
                    puts("There is h"); 
                    break;
                case 'd': 
                    puts("There is d"); 
                    break; 
                case 'l': 
                    puts("There is l"); 
                    break;
                case 'L': 
                    puts("There is L"); 
                    break;
                default:{
                            fprintf(stderr, "Usage: %s [-hdlL]", argv[0]);
                            return -1;
                        }

            }
    }

    return 0;
}

