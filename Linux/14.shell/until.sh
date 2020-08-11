#!/bin/bash

i=1
sum=0

until [ $i -gt 100 ]
do
	sum=$(($sum+$i))
	i=$(($i+1))
done

echo 1+2+···+100=$sum
