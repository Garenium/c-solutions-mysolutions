#ifndef HEADER 
#define HEADER 

#include <stdint.h>
#include <inttypes.h>
#include <string.h>

void print_tokens(char* firstToken, char* secondToken);

int gcf_table(char* argv[]);

uint64_t calculate_gcf(uint64_t n0, uint64_t n1);

#endif
