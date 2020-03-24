
if [ $1 == "--translate" ]
then
    echo "Translating to Python"
    cat $2 | ./bin/compiler --translate 2> /dev/null 1> $4
else
    echo "Compiling to MIPS..."
    cat $2 | ./bin/compiler 2> /dev/null 1> $4
fi