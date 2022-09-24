#include <stdio.h>
int main(){

    char* line;

    int i, j, gcf;

    i = 3;
    j = 6;
    gcf = 10;

    puts("Stops after line 12");
    snprintf(line, 60, "%d GCF %d = %d\n", i,j, gcf);
    printf("%s\n", line);

    return 0;
}
