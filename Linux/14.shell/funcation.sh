#!/bin/bash 

add()
{
	return $(($1+$2))
}

read -p "input two nums, space separated: " a b

add $a $b

echo $?
