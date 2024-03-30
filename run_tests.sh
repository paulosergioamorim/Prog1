#!/bin/bash

SOURCE=/mnt/c/Users/pamor/Downloads/"$1"
OUT_DIR=tests

if [ ! -d "$OUT_DIR" ]; then
    mkdir "$OUT_DIR"
fi

rm "$OUT_DIR"/*

gcc -o "$OUT_DIR"/prog "$1".c $2

for file in "$SOURCE"/input/*; do
    TEST=$(basename -- "$file")
    echo "\e[1mTesting "$TEST"\e[0m"
    "$OUT_DIR"/prog < "$SOURCE"/input/"$TEST" > "$OUT_DIR"/"$TEST"
    diff "$SOURCE"/output/"$TEST" "$OUT_DIR"/"$TEST"
done
