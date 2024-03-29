#!/bin/bash

SOURCE=/mnt/c/Users/pamor/Downloads/"$1"/input

gcc -o prog "$1".c $2

NUM_TESTS=$(find "$SOURCE" -type f | wc -l)

for n in $(seq 1 "$NUM_TESTS");
do
    ./prog < /mnt/c/Users/pamor/Downloads/"$1"/input/test_"$n" > ./test_"$n"
    diff /mnt/c/Users/pamor/Downloads/"$1"/output/test_"$n" ./test_"$n"
    rm ./test_"$n"
done

rm ./prog