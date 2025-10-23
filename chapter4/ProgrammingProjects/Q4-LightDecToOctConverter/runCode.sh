#! /bin/bash

for i in {1..10}; do
    x="$RANDOM"
    echo "Input: $x"
    ./lightDecToOctConverter "$x"
    #do ./lightDecToOctConverter "$i"
done
