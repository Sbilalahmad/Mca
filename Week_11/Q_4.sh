#!/bin/bash

echo "=== Basic Function Examples ==="
echo

# Example 1: Simple function without parameters
greet_user() {
    echo "Hello, welcome to the function demo!"
    echo "Today is: $(date)"
}

# Example 2: Function with parameters
personal_greet() {
    local name=$1
    local time_of_day=$2
    echo "Good $time_of_day, $name! Nice to see you."
}

# Example 3: Function that returns a value
calculate_sum() {
    local num1=$1
    local num2=$2
    local sum=$((num1 + num2))
    echo $sum  # Return the value by printing it
}

# Example 4: Function with return status
check_even() {
    local number=$1
    if [ $((number % 2)) -eq 0 ]; then
        return 0  # Success - even number
    else
        return 1  # Failure - odd number
    fi
}

# Calling the functions
echo "1. Simple greeting function:"
greet_user
echo

echo "2. Personalized greeting:"
personal_greet "Alice" "morning"
personal_greet "Bob" "evening"
echo

echo "3. Calculation function:"
result=$(calculate_sum 15 25)
echo "The sum of 15 and 25 is: $result"
echo

echo "4. Check even/odd using return status:"
check_even 10
if [ $? -eq 0 ]; then
    echo "10 is an even number"
else
    echo "10 is an odd number"
fi

check_even 7
if [ $? -eq 0 ]; then
    echo "7 is an even number"
else
    echo "7 is an odd number"
fi
echo
