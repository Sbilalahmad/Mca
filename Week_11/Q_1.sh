#!/bin/bash

# Check if filename is provided as argument
if [ $# -eq 0 ]; then
    echo "Error: Please provide a filename as argument"
    echo "Usage: $0 <filename>"
    exit 1
fi

filename="$1"

# Check if file exists
if [ -f "$filename" ]; then
    echo "File '$filename' exists."
else
    echo "File '$filename' does not exist."
fi
