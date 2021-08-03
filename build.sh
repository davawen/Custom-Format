#!/bin/bash
# Build the project, configure it with the -c flag and run it if the -r flag is specified

c_flag=''
r_flag=''

while getopts 'cr' flag;
do
	case "${flag}" in
		c) c_flag='true' ;;
		r) r_flag='true' ;;
	esac
done

if [[ "$c_flag" == 'true' ]]
then
	cmake -S . -B build
fi

(cd build && make)

if [[ "$r_flag" == 'true' ]]
then
	"./build/customFormat"
fi