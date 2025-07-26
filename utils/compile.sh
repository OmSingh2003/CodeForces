#!/bin/bash

# CodeForces C++ Compilation Script
# Usage: ./compile.sh filename.cpp [input.txt]

if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename.cpp> [input.txt]"
    exit 1
fi

filename="$1"
executable="${filename%.cpp}"
input_file="$2"

# Compile with CodeForces-friendly flags
echo "Compiling $filename..."
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o "$executable" "$filename"

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Compilation successful!"

# Run with input file if provided
if [ -n "$input_file" ] && [ -f "$input_file" ]; then
    echo "Running with input from $input_file:"
    echo "================================"
    ./"$executable" < "$input_file"
else
    echo "To run: ./$executable"
    echo "To run with input: ./$executable < input.txt"
fi
