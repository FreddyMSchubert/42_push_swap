#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <number_of_executions> <number_of_parameters>"
    exit 1
fi

number_of_executions=$1
number_of_parameters=$2
sum_operations=0
smallest=99999999999999
largest=-99999999999999

for (( i=0; i<number_of_executions; i++ ))
do
    operations=$(./run_push_swap.sh $number_of_parameters | tail -n 1)
    printf "Operation %d returned %d operations\n" $((i+1)) $operations
    sum_operations=$((sum_operations + operations))
    if [ "$operations" -lt "$smallest" ]; then
        smallest=$operations
    fi
    if [ "$operations" -gt "$largest" ]; then
        largest=$operations
    fi
done

average=$(echo "$sum_operations / $number_of_executions" | bc -l)

printf "Average number of operations: %.2f\n" $average
printf "Smallest number of operations: %d\n" $smallest
printf "Largest number of operations: %d\n" $largest
