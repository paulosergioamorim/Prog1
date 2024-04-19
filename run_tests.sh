#!/bin/bash

SOURCE=/mnt/c/Users/pamor/Downloads/"$1"
OUTPUT=tests

if [ ! -d "$OUTPUT" ]; then
    mkdir "$OUTPUT"
fi

rm "$OUTPUT"/*

gcc -o "$OUTPUT"/prog "$1".c $2

for file in "$SOURCE"/input/*; do
    TEST=$(basename -- "$file")
    echo "\e[1mTesting "$TEST"\e[0m"
    "$OUTPUT"/prog < "$SOURCE"/input/"$TEST" > "$OUTPUT"/"$TEST"
    diff "$SOURCE"/output/"$TEST" "$OUTPUT"/"$TEST"
done
