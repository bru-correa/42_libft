#!/bin/bash

## VARIABLES
# Template Setup
row_offset=24
space_between_col=15

# Color Definitions
default='\033[0m'
blue='\033[0;34m'
red='\033[0;31m'
green='\033[0;32m'
cyan='\033[36m'
purple='\033[35m'
yellow='\033[33m'

bold="\033[1m"
underline="\033[4m"

# Color Customizations
header_style=${purple}${underline}
correct="${green}O${default}"
wrong="${red}X${default}"
abrt="${yellow}A${default}"
bus="${yellow}B${default}"
segv="${yellow}S${default}"
timeout="${yellow}T${default}"

print_row()
{
	printf "${cyan}$1${default}"
	# Get the number of elements from the variable
	str_len=${#1}
	str_len=$(($row_offset-$str_len))
	print_spaces $str_len
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
	printf "${header_style}FUNCTIONS${default}"
	print_spaces space_between_col
	printf "${header_style}TESTS${default}"
	print_spaces space_between_col
	printf "${header_style}NORM${default}"
	print_spaces space_between_col
	printf "${header_style}RESULT${default}\n"
}

print_header
print_row isalpha
printf $correct
printf $wrong
printf $correct
printf $correct
printf $wrong
printf $wrong
printf "\n"

# Checks if the "function.c" passed as an argument exists
check_for_file()
{
	if [[ $(find ../ -type f -name ${1}.c | wc -l)  != 1 ]]; then
		printf "${red}Nothing turned in!${default}"
	fi
}

# Checks if the program will send an exit code, if not, run the test normally
run_test()
{
	print_row $1
	$(./bin/$1)
	exit_code=$?
	case $exit_code in
		134)
			printf $abrt
			;;
		135 | 138)
			printf $bus
			;;
		139)
			printf $segv
			;;
		14 | 142)
			printf $timeout
			;;
		# *)
			# Execute tests normally
			## ;;
	esac
	printf "\n"
}

run_test seg
run_test abrt
run_test bus
run_test timeout
# check_for_file islower
