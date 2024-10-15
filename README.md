# Minishell - 42 Network

## Overview

The **Minishell** project is a minimalistic shell implementation developed in C, as part of the curriculum at [42 Network](https://www.42.fr/). The goal of this project is to recreate the basic functionalities of a Unix shell, including command parsing, execution, and environment variable management. The project aims to deepen understanding of system calls, process management, and the overall workings of a shell.

## Table of Contents
1. [Features](#features)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Project Structure](#project-structure)
5. [Technical Details](#technical-details)
6. [License](#license)

## Features

- Command execution: Execute built-in and external commands.
- Support for piping and redirection of input and output.
- Environment variable management: Set, unset, and display environment variables.
- Basic command history: Navigate through previously executed commands.
- Error handling for command execution and parsing.

## Installation

### Prerequisites

- GCC or Clang compiler
- POSIX-compliant system (Linux or macOS recommended)

### Clone the Repository

```bash
git clone https://github.com/hihif/minishell.git
cd minishell
```

### Build the Project

To build the project, simply run:

```bash
make
```

This will create the `minishell` executable in the root directory.

### Clean Build

To remove the compiled files and object files:

```bash
make clean
```

To remove everything, including the executable:

```bash
make fclean
```

## Usage

To run the minishell, execute the following command:

```bash
./minishell
```

### Example

After starting the shell, you can type commands as you would in a regular Unix shell:

```bash
ls -l
echo $HOME
```

## Project Structure

- `src/`: Contains the source code files for the shell implementation.
- `include/`: Contains header files with function declarations and data structures.
- `makefile`: The makefile for building the project.

## Technical Details

### Command Parsing

- The shell reads input from the user, parses it into commands and arguments, and handles special characters (e.g., pipes, redirections).
- Implemented a lexer and parser to tokenize input and construct the execution tree.

### Process Management

- The shell uses `fork()` to create child processes for executing commands.
- Utilizes `execve()` for replacing the child process's image with the command to be executed.
- Handles waiting for child processes to complete using `wait()` and `waitpid()`.

### Environment Variables

- The shell supports managing environment variables through `getenv()`, `setenv()`, and `unsetenv()` functions.

### Error Handling

- Basic error handling is implemented for command execution, invalid commands, and memory allocation failures.
