#!/bin/bash
# gdb --args ./a.out 30 8

for ((i = 28; i<=31;i++))
do
    for((j=1; j <= 7; j++))
    do
        ./a.out $i $j
    done
done
