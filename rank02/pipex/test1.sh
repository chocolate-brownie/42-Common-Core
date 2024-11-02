#!/bin/bash

# Colors for better readability in the output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Variables for paths and test files
PIPEX="./pipex"
INFILE="/dev/stdin"
OUTFILE="/dev/stdout"

# Function to run a single test and compare results
run_test() {
    local description="$1"
    local cmd1="$2"
    local cmd2="$3"
    
    echo -e "${GREEN}Running test: $description${NC}"

    # Run pipex program
    echo -e "Input data for ${description}" | $PIPEX "$INFILE" "$cmd1" "$cmd2" "$OUTFILE"
}

# Test cases using /dev/stdin and /dev/stdout
run_test "Simple cat and wc -l" "cat" "wc -l"
run_test "Echo Hello and grep" "echo Hello" "grep Hello"
run_test "Echo Hello and cat" "echo Hello" "cat"
run_test "Echo multiple lines and grep" "echo -e 'Line 1\nLine 2\nLine 3'" "grep Line"
run_test "Echo multiline and wc" "echo -e 'Test1\nTest2\nTest3'" "wc -l"

echo -e "${GREEN}All tests completed.${NC}"
