#!/bin/bash

# Function to generate unique numbers
generate_numbers() {
    local count=$1
    local positive=$2
    local low_range=$3
    local num
    local nums=()

    while [ ${#nums[@]} -lt $count ]; do
        if [ "$positive" = true ]; then
            if [ "$low_range" = true ]; then
                num=$((RANDOM % 10))
            else
                num=$((RANDOM % 101))
            fi
        else
            if [ "$low_range" = true ]; then
                num=$((RANDOM % 10 * (RANDOM % 2 == 0 ? 1 : -1)))
            else
                num=$((RANDOM * RANDOM % 2147483647 * (RANDOM % 2 == 0 ? 1 : -1)))
            fi
        fi

        # Check if number is unique
        if [[ ! " ${nums[@]} " =~ " $num " ]]; then
            nums+=($num)
            echo -n "$num "
        fi
    done | xargs ../bin/push_swap
}

# Default values
NUMBER_OF_PARAMS=0
POSITIVE=false
LOW_RANGE=false

# Parse flags
while getopts ":hl" opt; do
    case $opt in
        h)
            POSITIVE=true
            ;;
        l)
            LOW_RANGE=true
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
    esac
done

# Remove the parsed options from the positional parameters
shift $((OPTIND -1))

# Check if the argument count is correct
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 [-h] [-l] <number_of_parameters>"
    exit 1
fi

NUMBER_OF_PARAMS=$1

generate_numbers $NUMBER_OF_PARAMS $POSITIVE $LOW_RANGE
