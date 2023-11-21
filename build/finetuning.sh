#!/bin/bash

# Path to the existing script
SCRIPT_PATH="./run_push_swap.sh"

# Function to calculate average
calculate_average() {
    local sum=0
    local count=$1
    shift
    if [ $count -eq 0 ]; then
        echo "0" # Avoid divide by zero
        return
    fi
    for num in "$@"; do
        sum=$(($sum + $num))
    done
    echo "scale=2; $sum / $count" | bc
}

# Check for correct number of arguments
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <low_number> <high_number> <times_to_run>"
    exit 1
fi

low=$1
high=$2
times_to_run=$3

# Loop over the range of numbers
for (( i=low; i<=high; i++ )); do
    echo "Processing number $i..."
    results=()

    # Run the script specified number of times
    for (( j=0; j<times_to_run; j++ )); do
        last_number=$($SCRIPT_PATH $i | tail -n1)
        # Check if last_number is a valid integer
        if [[ $last_number =~ ^[0-9]+$ ]]; then
            results+=($last_number)
        else
            echo "Invalid output received: $last_number"
        fi
    done

    # Calculate and print the average
    average=$(calculate_average "${#results[@]}" "${results[@]}")
    echo "Average for $i: $average"
done