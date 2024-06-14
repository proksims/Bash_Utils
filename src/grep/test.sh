#!/ bin / bash

counter_s=0
counter_f=0
counter=0
DIFF_RES=""
echo "" > log.txt
echo "-----------------------------"

for var in -i -v -c -l -n
do
    TEST1="$var int s21_grep.c "
    ./s21_grep $TEST1 > s21_grep.txt
    grep $TEST1 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST1"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST1"
    fi
    rm s21_grep.txt grep.txt
    
    TEST2="$var char s21_grep.c -i "
    ./s21_grep $TEST2 > s21_grep.txt
    grep $TEST2 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST2"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST2"
    fi
    rm s21_grep.txt grep.txt
    
    TEST3="$var for s21_grep.c Makefile "
    ./s21_grep $TEST3 > s21_grep.txt
    grep $TEST3 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST3"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST3"
    fi
    rm s21_grep.txt grep.txt
    
    TEST4="$var -e int s21_grep.c"
    ./s21_grep $TEST4 > s21_grep.txt
    grep $TEST4 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST4"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST4"
    fi
    rm s21_grep.txt grep.txt
    
    TEST5="-e ^int s21_grep.c $var"
    ./s21_grep $TEST5 > s21_grep.txt
    grep $TEST5 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST5"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST5"
    fi
    rm s21_grep.txt grep.txt
done
echo "-----------------------------"

for var in -v -c -l -n -h -s -o
do
    TEST1="int $var s21_grep.c "
    ./s21_grep $TEST1 > s21_grep.txt
    grep $TEST1 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST1"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST1"
    fi
    rm s21_grep.txt grep.txt
    
    TEST2="$var -i int s21_grep.c "
    ./s21_grep $TEST2 > s21_grep.txt
    grep $TEST2 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST2"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST2"
    fi
    rm s21_grep.txt grep.txt
    
    TEST3="-e while s21_grep.c -f mytest.txt $var "
    ./s21_grep $TEST3 > s21_grep.txt
    grep $TEST3 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST3"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST3"
    fi
    rm s21_grep.txt grep.txt
    
    TEST4="$var -e int s21_grep.c"
    ./s21_grep $TEST4 > s21_grep.txt
    grep $TEST4 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST4"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST4"
    fi
    rm s21_grep.txt grep.txt
    
    TEST5="-e for -e ^int s21_grep.c $var"
    ./s21_grep $TEST5 > s21_grep.txt
    grep $TEST5 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    (( counter++ ))
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
    then
        (( counter_s++ ))
        echo "success: grep $TEST5"
    else
        (( counter_f++ ))
        echo " fail: grep $TEST5"
    fi
    rm s21_grep.txt grep.txt
done
echo "-----------------------------"

for var in -v -c -l -n -h -s -o
do
    for var2 in -v -c -l -n -h -s -o
    do
        if [ $var != $var2 ]
        then
            TEST1="int $var s21_grep.c"
            ./s21_grep $TEST1 > s21_grep.txt
            grep $TEST1 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            (( counter++ ))
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( counter_s++ ))
                echo "success: grep $TEST1"
            else
                (( counter_f++ ))
                echo " fail: grep $TEST1"
            fi
            rm s21_grep.txt grep.txt
            
            TEST2="$var int s21_grep.c"
            ./s21_grep $TEST2 > s21_grep.txt
            grep $TEST2 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            (( counter++ ))
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( counter_s++ ))
                echo "success: grep $TEST2"
            else
                (( counter_f++ ))
                echo " fail: grep $TEST2"
            fi
            rm s21_grep.txt grep.txt
            
            TEST3="$var s21_grep.c -f mytest.txt "
            ./s21_grep $TEST3 > s21_grep.txt
            grep $TEST3 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            (( counter++ ))
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( counter_s++ ))
                echo "success: grep $TEST3"
            else
                (( counter_f++ ))
                echo " fail: grep $TEST3"
            fi
            rm s21_grep.txt grep.txt
            
            TEST4="$var -e int s21_grep.c"
            ./s21_grep $TEST4 > s21_grep.txt
            grep $TEST4 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            (( counter++ ))
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( counter_s++ ))
                echo "success: grep $TEST4"
            else
                (( counter_f++ ))
                echo " fail: grep $TEST4"
            fi
            rm s21_grep.txt grep.txt
            
            TEST5="-e for -e ^int s21_grep.c $var"
            ./s21_grep $TEST5 > s21_grep.txt
            grep $TEST5 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            (( counter++ ))
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
                (( counter_s++ ))
                echo "success: grep $TEST5"
            else
                (( counter_f++ ))
                echo " fail: grep $TEST5"
            fi
            rm s21_grep.txt grep.txt
        fi
    done
done
echo "-----------------------------"

echo "SUCCESS: $counter_s"
echo "FAIL: $counter_f"
