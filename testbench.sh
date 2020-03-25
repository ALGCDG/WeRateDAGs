#!bin/bash

compiler=$1

# rm -r -f ./tests/translator/out
# rm -r -f ./tests/compiler/out
# mkdir ./tests/translator/out
# mkdir ./tests/compiler/out
# for pyTest in ./tests/translator/tests/* ; do
#     testname="${pyTest##*/}" 
#     outdec=./tests/translator/out/$testname
#     mkdir $outdec
#     python3 "$pyTest/ref.py"
#     echo $? > $outdec/ref.out

#     cat $pyTest/in.c | $1 --translate 1> $outdec/out.py 2> $outdec/out.stderr
#     python3 $outdec/out.py
#     echo $? > $outdec/out.val
# done

no_tests=0
no_passes=0
rm TODO.txt
hitlist="./TODO.txt"
for section in ./compiler_tests/* ; do
    # echo $section
    for t in $section/* ; do
        if [[ $t == *"_driver"* ]]; then
            test_file=${t/_driver} # replace _driver with nothing
            driver=$t
            printf "Running test "
            printf $test_file
            printf " => "
            # running our code
            bin/c_compiler -S $test_file -o tmp.s 1> /dev/null
            mips-linux-gnu-gcc -mfp32 -c tmp.s -o tmp.o
            mips-linux-gnu-gcc -mfp32 -static $driver tmp.o
            rm tmp.s
            rm tmp.o
            timeout 5 qemu-mips a.out
            our_ret=$?
            rm a.out
            # running gcc code
            mips-linux-gnu-gcc -mfp32 -c $test_file -o tmp.o
            mips-linux-gnu-gcc -mfp32 -static $driver tmp.o
            rm tmp.o
            qemu-mips a.out
            perfect_ret=$?
            rm a.out
            if [[ $our_ret == $perfect_ret ]] ; then
                echo "PASSED"
                let "no_passes=no_passes+1"
            else
                echo $test_file >> $hitlist
                echo "FAILED "
            fi
            printf "WRD compiler returns: "
            printf $our_ret
            printf " GCC compiler returns: "
            echo $perfect_ret
            let "no_tests=no_tests+1"
        fi
    done
    # testname="${cTest##*/}"
    # echo $testname
    # outdec=./tests/compiler/out/$testname
    # echo $outdec
    # mkdir $outdec

    # cat $cTest/in.c | bin/compiler 1> $outdec/out_as.s 2> $outdec/out.stderr
    # mips-linux-gnu-gcc -mfp32 -c $outdec/out_as.s -o $outdec/tmp.o
    # if [ -f "$cTest/driver.c" ]
    # then
    #     mips-linux-gnu-gcc -mfp32 -static $cTest/driver.c $outdec/tmp.o -o $outdec/a.out
    # else
    #     mips-linux-gnu-gcc -mfp32 -static $outdec/tmp.o -o $outdec/a.out
    # fi
    # echo "emulating"
    # qemu-mips $outdec/a.out
    # echo $? > $outdec/out.val
done
echo $no_passes "/" $no_tests "tests passed"