#!/bin/bash

RED="\033[1;31m"
GREEN="\033[1;32m"
NOCOLOR="\033[0m"

ERROR="0"
./tests/seg > /dev/null 2>&1 | :
case $? in
	134)
		echo -e "${RED} A ${NOCOLOR}"
		;;
	139)
		echo -e "${RED} S ${NOCOLOR}"
		;;
esac
echo $ERROR
