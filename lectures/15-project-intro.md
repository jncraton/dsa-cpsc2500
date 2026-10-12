---
reading: '[Sorting Complexity](https://github.com/jncraton/sorting-complexity-f26)'
teaching_goal: Students will understand computational complexity through the implementation of sorting algorithms and container classes.
learning_objectives:
  - Compare computational complexity of sorting algorithms
  - Implement standard container methods in C++
  - Use a test harness to measure wall time and operation counts
  - Understand open science practices in software development
---

# Sorting Complexity

## Complexity Theory

Complexity theory helps us understand how algorithms scale

## Learning Goals

- Compare sorting algorithm performance
- Implement C++ container methods
- Measure wall time and operations
- Practice open science

## The Task

Implement sorting methods in C++ containers

- `list`
- `forward_list`
- `vector`

## Container Methods

Implement these standard operations:

- `at`, `[]`
- `front`, `back`
- `insert`
- `push_back`, `push_front`
- `pop_back`, `pop_front`
- `clear`

## Sorting Algorithms

Implement these sorting methods

- Bubble
- Insertion
- Selection
- Merge
- Quick
- Heap
- Shell
- Tim

## Measuring Performance

We measure two primary metrics

- Wall time (execution speed)
- Comparison counts (algorithmic efficiency)

## TrackedInt

A custom class to count operations

```cpp
// Example usage
TrackedInt a = 5;
TrackedInt b = 10;
TrackedInt c = a + b;
```

## The Test Harness

The `bench` program automates testing

- Runs operations on various sizes
- Records results to `bench.csv`
- Uses `TrackedInt` for counts

## Building the Project

Use the provided `makefile`

```sh
make
```

## Analysis Pipeline

1. Compile with `g++ -std=c++23`
2. Run `bench` to collect data
3. Run `analyze.py` to process CSV
4. View `index.html` dashboard

## Dashboard

The dashboard visualizes the data

- Compares containers
- Compares algorithms
- Shows scaling trends

## Open Science

We follow open science principles

- Reproducible workflows
- Shared codebases
- Peer review via pull requests

## Todo

Implement the basic container methods so that our tests pass
