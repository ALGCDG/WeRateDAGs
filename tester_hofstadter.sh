#!/bin/bash

cat $1 | bin/compiler 2> /dev/null 1> tmp.s
mips-linux-gnu-gcc -mfp32 -c tmp.s -o tmp.o
mips-linux-gnu-gcc -mfp32 -static tmp/main_hofstadter.c tmp.o
rm tmp.s
rm tmp.o
qemu-mips a.out
ret=$?
rm a.out
printf "simulation returns: "
echo $ret
