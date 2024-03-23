#!/bin/bash

gcc -o prog $2

for n in $(seq 1 7);
do
    ./prog < /mnt/c/Users/pamor/Downloads/$1/input/test_$n > ./out/test_$n
    diff /mnt/c/Users/pamor/Downloads/$1/output/test_$n ./out/test_$n
done