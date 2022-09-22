#define __STDC_FORMAT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(){

    uint64_t num = 2348230498230948;
    printf("%"PRIu64"\n", num);
    return 0;
}
