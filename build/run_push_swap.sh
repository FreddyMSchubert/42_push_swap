#!/bin/bash

# Check if the argument count is correct
if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <number_of_parameters>"
	exit 1
fi

NUMBER_OF_PARAMS=$1

for i in $(seq 1 $NUMBER_OF_PARAMS); do
    echo -n "$((RANDOM * RANDOM % 2147483647 * (RANDOM % 2 == 0 ? 1 : -1))) "
done | xargs ../bin/push_swap

# - used RANDOM * RANDOM to increase the range.
# - `xargs ../bin/push_swap` passes the generated numbers to program
