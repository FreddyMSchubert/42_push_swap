#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <low_number> <high_number> <times_to_run>"
    exit 1
fi

low=$1
high=$2
times_to_run=$3

for (( i=low; i<=high; i++ )); do
    output=$(./get_average.sh $times_to_run $i | tail -n3)
    
    average=$(echo "$output" | grep 'Average number of operations:' | awk '{print $NF}')
    smallest=$(echo "$output" | grep 'Smallest number of operations:' | awk '{print $NF}')
    largest=$(echo "$output" | grep 'Largest number of operations:' | awk '{print $NF}')
    
    echo "average for number $i: $average. lowest: $smallest. highest: $largest"
done
