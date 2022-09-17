#!/bin/bash
#Note that this is EXTREMELY SLOW
#I didn't want to rewrite my C code with a testing while loop
#So I made a bash script instead. It is ideal for short ranges and
#is never meant to be for long ranges.
#Not done
GREEN='\033[0;32m'
NC='\033[0m' # No Color
for i in {-10..10}
do
    for j in {-10..10}
    do
        ./a.out $i $j >> log.txt
        GCD=$((awk '{print $NF}' log.txt))
        # GCD==$((i % j)) && Valid
        
    done
done
