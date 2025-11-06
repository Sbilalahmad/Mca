#!/bin/bash

echo "=== Basic Conditional Statements Demo ==="
echo

# Example 1: Check if a number is positive, negative, or zero
echo "1. Number Check:"
read -p "Enter a number: " num

if [ $num -gt 0 ]; then
    echo "   $num is positive"
elif [ $num -lt 0 ]; then
    echo "   $num is negative"
else
    echo "   The number is zero"
fi
echo

# Example 2: Check file existence and type
echo "2. File Check:"
read -p "Enter a file/directory path: " filepath

if [ -f "$filepath" ]; then
    echo "   '$filepath' is a regular file"
elif [ -d "$filepath" ]; then
    echo "   '$filepath' is a directory"
elif [ -e "$filepath" ]; then
    echo "   '$filepath' exists but is not a regular file or directory"
else
    echo "   '$filepath' does not exist"
fi
echo

# Example 3: String comparison
echo "3. String Comparison:"
read -p "Enter first string: " str1
read -p "Enter second string: " str2

if [ "$str1" = "$str2" ]; then
    echo "   Strings are equal"
else
    echo "   Strings are different"
fi

if [ -z "$str1" ]; then
    echo "   First string is empty"
fi

if [ -n "$str2" ]; then
    echo "   Second string is not empty"
fi
echo
