<div align="center">
  <img src="https://github.com/user-attachments/assets/e5718959-80aa-4749-ac26-4588d4b1dabd" alt="gt">
</div>



# Philosophers - Dining Philosophers Problem Implementation

A multi-threaded simulation of the classic dining philosophers problem implemented in C using POSIX threads and mutexes.

## Overview

This project implements the dining philosophers problem where N philosophers sit around a circular table, alternating between thinking and eating. Each philosopher needs two forks to eat, but there are only N forks available (one between each pair of adjacent philosophers). The challenge is to prevent deadlock and starvation while maximizing concurrency. [1](#0-0) 

## Features

- **Deadlock Prevention**: Uses ordered resource acquisition based on circular list structure
- **Thread Safety**: Individual mutex for each fork plus global synchronization mutexes
- **Death Detection**: Continuous monitoring without interfering with eating process
- **Memory Management**: Proper allocation/deallocation with comprehensive error handling
- **Input Validation**: Robust command-line argument processing with detailed error messages

## Usage

```bash
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Parameters

- `number_of_philosophers`: Number of philosophers (1-200)
- `time_to_die`: Time in milliseconds before a philosopher dies (≥60ms)
- `time_to_eat`: Time in milliseconds to eat (≥60ms) 
- `time_to_sleep`: Time in milliseconds to sleep (≥60ms)
- `number_of_times_each_philosopher_must_eat`: Optional parameter for simulation termination [2](#0-1) 

## Build System

The project uses a Makefile with the following targets:

- `make` or `make all`: Compile the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Full rebuild [3](#0-2) 

## Architecture

### Core Data Structures

- **`t_philo_inf`**: Global simulation configuration and state
- **`t_ph`**: Individual philosopher nodes in circular linked list structure [4](#0-3) 

### Thread Management

Each philosopher runs in its own detached thread, with staggered startup to reduce initial contention: [5](#0-4) 

### Synchronization Strategy

- **Fork Mutexes**: One mutex per philosopher for fork access
- **Global Mutexes**: `pth_lock` for synchronized output, `allow_eat` for eating control
- **Ordered Acquisition**: Prevents circular wait conditions

## Error Handling

Comprehensive input validation with specific error messages for different parameter violations: [6](#0-5) 

## Memory Management

Systematic cleanup of all allocated resources including mutex destruction and memory deallocation: [7](#0-6) 

## Example

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same as above, but stop after each philosopher eats 7 times
./philo 5 800 200 200 7
```

## Notes

This implementation demonstrates key concurrency concepts including resource management, deadlock avoidance, thread lifecycle management, and synchronized state monitoring. The solution uses fine-grained locking with individual fork mutexes while maintaining global coordination through shared state mutexes.

