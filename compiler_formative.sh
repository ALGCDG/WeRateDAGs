#!/bin/bash

for d1 in ./compiler_tests ; do
    for d2 in ./compiler_tests/$d1/*_driver.c ; do
        cat ./compiler_tests/$d1/${d2#_driver} | bin/compiler 2> /dev/null 1> tmp.s
        mips-linux-gnu-gcc -mfp32 -c tmp.s -o tmp.o
        mips-linux-gnu-gcc -mfp32 -static tmp/main.c tmp.o

