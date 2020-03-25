#!bin/bash

compiler=$1

rm -r -f ./tests/translator/out
rm -r -f ./tests/compiler/out
mkdir ./tests/translator/out
mkdir ./tests/compiler/out
for pyTest in ./tests/translator/tests/* ; do
    testname="${pyTest##*/}" 
    outdec=./tests/translator/out/$testname
    mkdir $outdec
    python3 "$pyTest/ref.py"
    echo $? > $outdec/ref.out

    cat $pyTest/in.c | $1 --translate 1> $outdec/out.py 2> $outdec/out.stderr
    python3 $outdec/out.py
    echo $? > $outdec/out.val
done

for cTest in ./tests/compiler/tests/* ; do
    echo $cTest
    testname="${cTest##*/}"
    echo $testname
    outdec=./tests/compiler/out/$testname
    echo $outdec
    mkdir $outdec

    cat $cTest/in.c | bin/compiler 1> $outdec/out_as.s 2> $outdec/out.stderr
    mips-linux-gnu-gcc -mfp32 -c $outdec/out_as.s -o $outdec/tmp.o
    if [ -f "$cTest/driver.c" ]
    then
        mips-linux-gnu-gcc -mfp32 -static $cTest/driver.c $outdec/tmp.o -o $outdec/a.out
    else
        mips-linux-gnu-gcc -mfp32 -static $outdec/tmp.o -o $outdec/a.out
    fi
    echo "emulating"
    qemu-mips $outdec/a.out
    echo $? > $outdec/out.val
done