#!/bin/bash

read -p "input a num: " num

if [ ! $num ]
then
	echo no num
	exit -1
fi

case $num in
	"5")
		echo num == 5
		;;
	"10")
		echo num == 10
		;;
	*)
		echo num != 5/10
		;;
esac
