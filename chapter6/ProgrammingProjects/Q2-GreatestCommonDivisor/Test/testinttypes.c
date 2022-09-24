#define __STDC_FORMAT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
int main(){

    uint64_t num = 2348230498230948;
    printf("%"PRIu64"\n", num);

    printf("%u\n", UINT_MAX);
    return 0;
}
