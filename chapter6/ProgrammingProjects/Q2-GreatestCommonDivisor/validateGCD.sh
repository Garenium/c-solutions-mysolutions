#!/bin/bash
#Note that this is EXTREMELY SLOW
#The following script is ideal for short ranges and
#is never meant to be for long ranges.
#Not done
GREEN='\033[1;32m'
NC='\033[0m' # No Color
TARGET_FILE="logs/log.txt"

> "${TARGET_FILE}" 

for i in {1..10}
do
    for j in {1..10}
    do
        IANDJ="\n$GREEN$i $j$NC\n"

        printf "${IANDJ}"
        printf "${IANDJ}">>logs/log.txt

        #spaceing
        >>"${TARGET_FILE}" 
        # ./a.out $i $j >>"${TARGET_FILE}" #print binary output
          GCD=./a.out $i $j | tail -n 1 "${TARGET_FILE}" | awk '{print $NF}' #print binary output
          GCD==$(($i % $j)) && echo "valid"
        >>"${TARGET_FILE}" 



        # GCD=tail -n 1 logs/log.txt | awk '{print $NF}'
        # echo "${GCD}"
        #GCD==$((i % j)) && Valid

        # ./a.out
        
    done
done
