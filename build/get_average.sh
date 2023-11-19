#!/bin/bash

execute_and_sum_operations() {
    local count=$1
    local total_operations=0
    local execution_count=500
    local operations
    local i
    local seed

    for ((i = 0; i < execution_count; i++)); do
        # Generate a seed using the current time in seconds and a portion of nanoseconds
        seed=$(date +%s)$((RANDOM % 1000))

        # Generate random numbers using AWK with the seed
        numbers=$(awk -v count=$count -v seed=$seed 'BEGIN {
            srand(seed);
            for (i = 0; i < count; i++) {
                printf("%d ", int(rand() * 1000) - 500);
            }
        }')

        echo "Run $((i + 1)): Generating numbers $numbers"
        operations=$("../bin/push_swap" $numbers | tail -1 | grep -o '[0-9]\+')
        echo "Operations: $operations"
        total_operations=$((total_operations + operations))
    done

    echo "Average operations: $((total_operations / execution_count))"
}

NUMBER_OF_PARAMS=0

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number_of_parameters>"
    exit 1
fi

NUMBER_OF_PARAMS=$1

execute_and_sum_operations $NUMBER_OF_PARAMS
