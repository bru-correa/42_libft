#!/bin/bash

## VARIABLES
# Directory Location
bin="./bin"
logs="./logs"

# Template Setup
row_offset=20
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
passed="${green}PASSED${default}"
failed="${red}FAILED${default}"
ok="${green}O.K.${default}"
ko="${red}K.O.${default}"
empty="${red}EMPTY$default"

# Possible Results
result_ok="O.K."
result_ko=-"K.O."
result_empty="EMPTY"

print_row()
{
	# Get the number of elements from the variable
	str_len=${#1}
	str_len=$(($row_offset-$str_len))
	print_spaces $str_len
}

print_row_n()
{
	str_len=$(($row_offset-$1))
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
	print_row FUNCTIONS
	printf "${header_style}NORM${default}"
	print_row NORM
	printf "${header_style}TESTS${default}"
	print_row TESTS
	printf "${header_style}RESULT${default}\n"
}

print_name()
{
	printf "${cyan}$1${default}"
	print_row $1
}

# Checks if the "function.c" passed as an argument exists
check_for_file()
{
	if [[ $(find ../ -maxdepth 1 -type f -name ${1}.c | wc -l) != 1 ]]; then
		result=$result_empty
	fi
}

check_norm()
{
	norm=$(norminette ../$1.c | tr -d '\n' | tail -c 3)
	if [[ "$norm" = "OK!" ]]; then
		printf $passed
		print_row PASSED
	else
		printf $failed
		result=$result_ko
		print_row FAILED
	fi
}

# Checks if the program will send an exit code, if not, run the test normally
run_tests()
{
	mkdir -p $logs/$1
	current_test=1
	test_output_length=0
	while [[ current_test -gt 0 ]]
	do
		test_output=$(${bin}/${1} ${current_test})
		exit_code=$?
		case $exit_code in
			134)
				printf $abrt
				result=$result_ko
				current_test=$(($current_test+1))
				;;
			135 | 138)
				printf $bus
				result=$result_ko
				current_test=$(($current_test+1))
				;;
			139)
				printf $segv
				result=$result_ko
				current_test=$(($current_test+1))
				;;
			14 | 142)
				printf $timeout
				result=$result_ko
				current_test=$(($current_test+1))
				;;
			*)
				if [ -z "${test_output}" ]; then
					current_test=0
				else
					if [[ $(printf "${test_output}" | tail -c 2) -eq "OK" ]]; then
						printf $correct
						test_output_length=$(($test_output_length+1))

					else
						printf $wrong
						result=$result_ko
						test_output_length=$(($test_output_length+1))
					fi
					printf "${test_output}" > $logs/$1/$1$current_test.txt
					current_test=$(($current_test+1))
				fi
				;;
		esac
	done
	print_row_n test_output_length
}

print_result()
{
	case $result in
		$result_ok)
			printf $ok
			;;
		$result_ko)
			printf $ko
			;;
		$result_empty)
			printf $empty
			;;
	esac
	printf "\n"
}

begin_test()
{
	result=$result_ok
	mkdir -p $logs/$1
	print_name $1
	check_for_file $1
	if [[ "$result" = "$result_empty" ]]; then
		print_row_n 0
		print_row_n 0
	else
		check_norm $1
		run_tests $1
	fi
	print_result
}

test_all()
{
	current_test=1
	test_files=$(find ./src/tests/ -type f -name "*.c" | xargs -n 1 basename --suffix=".c")
	test_files_amount=$(find ./src/tests/ -type f -name "*.c" | wc -l)
	if [[ $current_test -le $test_files_amount ]]; then
		begin_test $(printf ${test_files} | sed -n "${current_test}p")
		current_test=$(($current_test+1))
	fi
}
print_header
test_all
