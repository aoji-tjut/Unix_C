#!/bin/bash

read -p "input a num: " num

if [ ! $num ]
then
	echo no num
	exit -1
elif [ $num -ge 10 ]
then
	echo num '>=' 10
elif [ $num -ge 5 ]
then
	echo 10 '>' num '>=' 5
else
	echo num '<' 5
fi
