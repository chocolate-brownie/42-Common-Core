# pipex
Pipex is a 42 School project that recreates the shell's pipeline (|) functionality in C. It takes an input file, executes two commands, and writes the output to a file, simulating

```bash
< infile cmd1 | cmd2 > outfile
```

In this project, you will learn how to work with pipes, file descriptors, and process control in Unix-like systems.

## Table of Contents
- [What is Pipex?](#what-is-pipex)
- [How it Works](#how-it-works)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Usage](#usage)
- [Roadmap to Build the Project](#roadmap-to-build-the-project)
  - [Step 1: Understand the Shell Pipeline](#step-1-understand-the-shell-pipeline)
  - [Step 2: Set Up the Project](#step-2-set-up-the-project)
  - [Step 3: Handle File I/O](#step-3-handle-file-io)
  - [Step 4: Create a Pipe](#step-4-create-a-pipe)
  - [Step 5: Fork and Execute Commands](#step-5-fork-and-execute-commands)
  - [Step 6: Error Handling](#step-6-error-handling)
  - [Step 7: Test with Edge Cases](#step-7-test-with-edge-cases)
- [Memory Leak Checking](#memory-leak-checking)
- [Conclusion](#conclusion)

## What is Pipex?

Pipex simulates the behavior of the shell when using the `|` (pipe) operator, redirecting input from a file, passing it through two commands, and then redirecting the output to another file. The project helps you become familiar with Unix system calls like `pipe()`, `fork()`, `execve()`, and `dup2()`.

## How it Works

Pipex follows these steps:
1. Opens an input file (`infile`) for reading.
2. Opens or creates an output file (`outfile`) for writing.
3. Sets up a pipe to communicate between two processes.
4. Forks two child processes: the first executes the first command (`cmd1`) with its input redirected from the input file, and the second executes the second command (`cmd2`) with its input redirected from the pipe’s output.
5. Writes the result of the second command to the output file.

## Project Structure

```
.
├── Makefile            # To compile the project
├── srcs/               # Directory with source files
│   ├── pipex.c         # Main pipex logic
│   ├── child_processes.c # Handles forked child processes
│   ├── execute.c       # Handles command execution
│   ├── get_command_path.c # Resolves the command path using environment variables
│   ├── ft_getenv.c     # Custom getenv function
│   ├── ft_free_split.c # Utility to free allocated arrays
│   └── error.c         # Error handling functions
├── includes/           # Directory for header files
│   └── pipex.h         # Header file with function declarations and structure definitions
├── libft/              # Libft library (utility functions like ft_split)
└── README.md           # This README file
```

## Compilation

To compile the project, simply run:

```bash
make
```

This will compile the `pipex` program and any required libraries, including your `libft`.

## Usage

Once compiled, you can run the `pipex` program with the following format:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Example:

```bash
./pipex file1 "grep Hello" "wc -l" file2
```

This command will take `file1`, run `grep Hello`, then pass the result to `wc -l`, and save the final output to `file2`.

## Roadmap to Build the Project

### Step 1: Understand the Shell Pipeline

Before diving into code, understand how the shell's `|` (pipe) works. In the shell, when you execute:

```bash
cmd1 | cmd2
```

It creates two processes: `cmd1` writes its output to a pipe, and `cmd2` reads the input from the pipe. Your task is to mimic this behavior programmatically.

### Step 2: Set Up the Project

1. **Create your file structure**: 
   - `srcs/` for source files, `includes/` for headers.
   - Add the `pipex.h` header file where you'll declare your functions and structures.
   - Make sure your `Makefile` can compile all your `.c` files and link the `libft` library.

2. **Include Libft**: 
   - You'll need some helper functions, like `ft_split`, for splitting command strings. This can be included from your `libft`.

### Step 3: Handle File I/O

- **Open the input and output files** using `open()`:
  - For `infile`, use `O_RDONLY` (read only).
  - For `outfile`, use `O_WRONLY | O_CREAT | O_TRUNC` (write only, create if not exists, and truncate).
  
- **Redirect file descriptors**:
  - Use `dup2()` to redirect input and output from these files.

### Step 4: Create a Pipe

- Use the `pipe()` system call to create a pipe:
  - This creates a pair of file descriptors: one for reading, one for writing.
  
- The parent process will manage the pipe:
  - The first child will write to the pipe (output from `cmd1`).
  - The second child will read from the pipe (input to `cmd2`).

### Step 5: Fork and Execute Commands

1. **Fork two child processes**:
   - The first child will execute `cmd1`.
   - The second child will execute `cmd2`.

2. **Replace the current process image** in each child using `execve()`:
   - `execve()` allows you to run an external program (e.g., a command like `grep`).
   - Use your custom `ft_getenv()` to locate the `PATH` variable and find the correct executable path for the command.

3. **Close unused file descriptors**:
   - Ensure that each process closes file descriptors it doesn't need (e.g., the pipe's write end in the reading process).

### Step 6: Error Handling

- Use `perror()` or custom error messages to handle various errors such as:
  - File not found.
  - Permission denied.
  - Invalid command.
  
- Handle edge cases gracefully:
  - Empty files.
  - Invalid commands.
  - Large files or streams like `/dev/zero`.

### Step 7: Test with Edge Cases

- Test the program using `/dev/stdin` and `/dev/stdout` to ensure that it can handle standard input/output.
- Test with large inputs like `/dev/zero` to see how the program manages heavy I/O.
- Test various invalid scenarios to ensure proper error handling.

## Memory Leak Checking

It's important to check for memory leaks using **Valgrind**:

```bash
valgrind --leak-check=full --track-origins=yes ./pipex infile "cmd1" "cmd2" outfile
```

Fix any memory leaks by ensuring that you `free()` dynamically allocated memory, especially when using functions like `ft_split`.
