#!/bin/bash

ls * > ls.log

sum=0

for i in $(cat ls.log)
do
	sum=$(($sum+1))
done

echo $sum files

rm -rf ls.log

#------------------------

sum=0

for((i=1;i<=100;i++))
do
	sum=$(($sum+$i))
done

echo 1+2+···+100=$sum
