#!/bin/bash

generate_numbers() {
	local count=$1
	local num
	local nums=()

	while [ ${#nums[@]} -lt $count ]; do
		num=$((RANDOM * RANDOM % 2147483647 * (RANDOM % 2 == 0 ? 1 : -1)))
		
		# Check if number is unique
		if [[ ! " ${nums[@]} " =~ " $num " ]]; then
			nums+=($num)
			echo -n "$num "
		fi
	done | xargs ../push_swap
}

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number_of_parameters>"
    exit 1
fi

NUMBER_OF_PARAMS=$1

generate_numbers $NUMBER_OF_PARAMS
