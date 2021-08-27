#!/bin/bash

row_offset=29
space_between=20

default='\033[0m'
blue='\033[0;34m'
red='\033[0;31m'
green='\033[0;32m'
cyan='\033[36m'
purple='\033[35m'

bold="\033[1m"
underline="\033[4m"

correct="${green}O${default}"
wrong="${red}X${default}"

print_row()
{
	printf "${cyan}$1${default}"
	# Get the number of elements from the variable
	str_len=${#1}
	str_len=$(($row_offset-$str_len))
	while [ "$str_len" -gt "0" ]; do
		printf " "
		str_len=$(($str_len-1))
	done
}

print_spaces()
{
	space_amount=$1
	for ((i=0; i<space_amount; i++)); do
		printf " "
	done
}

print_header()
{
	printf "${purple}${underline}FUNCTIONS${default}"
	print_spaces space_between
	printf "${purple}${underline}TESTS${default}\n"
}

print_header
print_row isalpha
printf $correct
printf $wrong
printf $correct
printf $correct
printf $wrong
printf $wrong
