#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <number_of_executions> <number_of_parameters>"
    exit 1
fi

number_of_executions=$1
number_of_parameters=$2
sum_operations=0
smallest=99999999  # Initialize to a large value
largest=-99999999  # Initialize to a small value

for (( i=0; i<number_of_executions; i++ ))
do
    # Execute the previous script and capture the last line of output
    operations=$(./run_push_swap.sh $number_of_parameters | tail -n 1)
    
    # Print the current operation number and the value it returned
    printf "Operation %d returned %d operations\n" $((i+1)) $operations

    # Add the number of operations to the sum
    sum_operations=$((sum_operations + operations))

    # Check and update the smallest and largest values
    if [ "$operations" -lt "$smallest" ]; then
        smallest=$operations
    fi

    if [ "$operations" -gt "$largest" ]; then
        largest=$operations
    fi
done

# Calculate the average
average=$(echo "$sum_operations / $number_of_executions" | bc -l)

# Display the average, smallest, and largest number of operations
printf "Average number of operations: %.2f\n" $average
printf "Smallest number of operations: %d\n" $smallest
printf "Largest number of operations: %d\n" $largest
