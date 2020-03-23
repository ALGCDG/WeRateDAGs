#!/bin/bash

mips-linux-gnu-gcc -mfp32 -O0 -c $1 -o tmp.o
mips-linux-gnu-objdump -D tmp.o > tmp.s
cat tmp.s
rm tmp.o
rm tmp.s
