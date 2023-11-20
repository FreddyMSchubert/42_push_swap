#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <number_of_executions> <number_of_parameters>"
    exit 1
fi

number_of_executions=$1
number_of_parameters=$2
sum_operations=0

for (( i=0; i<number_of_executions; i++ ))
do
    # Execute the previous script and capture the last line of output
    operations=$(./run_push_swap.sh $number_of_parameters | tail -n 1)
    
    # Add the number of operations to the sum
    sum_operations=$((sum_operations + operations))
done

# Calculate the average
average=$(echo "$sum_operations / $number_of_executions" | bc -l)

# Display the average
printf "Average number of operations: %.2f\n" $average
