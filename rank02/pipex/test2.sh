#!/bin/bash

# Colors for output formatting
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Variables for paths and test files
PIPEX="./pipex"
INFILE="/dev/stdin"
OUTFILE="/dev/stdout"
TEMP_INFILE="temp_infile"
TEMP_OUTFILE="temp_outfile"
ERR_OUTFILE="error_output"
LOGFILE="test_pipex.log"

# Function to run a single test
run_test() {
    local description="$1"
    local cmd1="$2"
    local cmd2="$3"
    local infile="$4"
    local outfile="$5"

    echo -e "${YELLOW}Running test: $description${NC}" | tee -a $LOGFILE
    # Adding a timeout of 5 seconds to avoid infinite loops
    if echo -e "$description" | timeout 5s $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile" >> $LOGFILE 2>>$ERR_OUTFILE; then
        echo -e "${GREEN}Test passed${NC}" | tee -a $LOGFILE
    else
        echo -e "${RED}Test failed!${NC}" | tee -a $LOGFILE
        echo "Check the log file ($LOGFILE) and error output ($ERR_OUTFILE) for details." | tee -a $LOGFILE
    fi
    echo -e "\n-----------------------------------\n" >> $LOGFILE
}

# Clean log and temp files
> $LOGFILE
> $ERR_OUTFILE

# Prepare a temporary infile for tests
echo -e "This is a temporary test file\nPipex test cases" > $TEMP_INFILE

echo "Running extensive pipex tests..." | tee $LOGFILE

# VALID TEST CASES (Expected to Pass)

run_test "Valid Test: cat and wc -l" "cat" "wc -l" $TEMP_INFILE $TEMP_OUTFILE
run_test "Valid Test: ls and grep" "ls" "grep pipex" $TEMP_INFILE $TEMP_OUTFILE
run_test "Valid Test: echo and grep" "echo Hello" "grep H" $INFILE $OUTFILE
run_test "Valid Test: cat and wc -c" "cat" "wc -c" $TEMP_INFILE $TEMP_OUTFILE

# ERROR HANDLING TESTS (Expected to Fail)

run_test "Error: Non-existent infile" "ls" "wc -l" "non_existent_file" $TEMP_OUTFILE
run_test "Error: Invalid command" "nonexistentcmd" "wc -l" $TEMP_INFILE $TEMP_OUTFILE
run_test "Error: Invalid output file path" "ls" "wc -l" $TEMP_INFILE "/invalid/path"
run_test "Error: No permissions for infile" "ls" "wc -l" "/etc/shadow" $TEMP_OUTFILE

# EDGE CASES (Unusual but possible inputs)

run_test "Edge Case: Empty input file" "cat" "wc -l" "/dev/null" $TEMP_OUTFILE
run_test "Edge Case: Large file handling" "head -c 1000 /dev/zero" "wc -c" $INFILE $OUTFILE
run_test "Edge Case: /dev/stdin and /dev/stdout" "cat" "wc -l" $INFILE $OUTFILE
run_test "Edge Case: Special characters in commands" "echo 'hello$%^&*()'" "grep 'hello'" $INFILE $OUTFILE

# MEMORY LEAK CHECKING (With Valgrind)
echo -e "${YELLOW}Running Valgrind tests for memory leaks...${NC}" | tee -a $LOGFILE

valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
    $PIPEX $TEMP_INFILE "cat" "wc -l" $TEMP_OUTFILE 2>>$ERR_OUTFILE | tee -a $LOGFILE

echo -e "${GREEN}All tests completed. Check the log file (${LOGFILE}) for detailed results.${NC}"
