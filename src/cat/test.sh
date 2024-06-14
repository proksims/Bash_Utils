#!/bin/bash

TEST_FILE="mytest.txt"
TEST_FILE2="Makefile"
DIFF=""
echo "" > log.txt

#TEST1 FILE1
TEST="$TEST_FILE"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt

#TEST2 FILE1 FILE 2
TEST="$TEST_FILE $TEST_FILE2"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt

#TEST3 -b FILE1
TEST="-b $TEST_FILE"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt

#TEST4 -e FILE1
TEST="-e $TEST_FILE"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt

#TEST5 -n FILE1
TEST="-n $TEST_FILE"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt

#TEST6 -s FILE1
TEST="-s $TEST_FILE"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt

#TEST7 -t FILE1
TEST="-t $TEST_FILE"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt

#TEST8 -v FILE1
TEST="-v $TEST_FILE"
echo "-----------------------------"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
DIFF="$(diff -s s21_cat.txt cat.txt)"
if [ "$DIFF" == "Files s21_cat.txt and cat.txt are identical" ]
then
    echo "success"
else
    echo "fail"
    echo "$TEST" >> log.txt
fi
rm s21_cat.txt cat.txt
