---
reading: '[Binsort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BinSort.html), [Radix Sort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/RadixSort.html)'
teaching_goal: Students will understand the mechanics of Binsort and Radix Sort, including their strengths and limitations.
learning_objectives:
  - Describe the basic Binsort algorithm and its complexity
  - Identify the limitations of Binsort regarding key ranges
  - Explain how Radix Sort overcomes Binsort's limitations
  - Understand the role of the radix (base) in Radix Sort
  - Analyze the time complexity of Radix Sort in terms of digits and records
---

# Binsort and Radix Sort

## Binsort Overview

- Non-comparison based sorting
- Assigns records to bins based on key values
- Each bin holds records with the same key
- Sorts by placing items in their final position

## Basic Binsort

- Works for permutations of $0$ to $n-1$
- Direct mapping: $B[A[i]] = A[i]$
- Time complexity: $O(n)$
- Very efficient but highly restricted

## Extended Binsort

- Handles duplicate keys
- Handles keys in range $0$ to $MaxKeyValue$
- Uses linked lists for bins
- Complexity: $O(n + MaxKeyValue)$

## Binsort Limitations

- Performance degrades as $MaxKeyValue$ grows
- If $MaxKeyValue = n^2$, complexity is $O(n^2)$
- Large key ranges require massive memory for bins
- Not practical for large, sparse key ranges

## Radix Sort

- Solves Binsort's range problem
- Breaks keys into digits
- Sorts by one digit at a time
- Processes from Least Significant Digit (LSD) to Most Significant Digit (MSD)
- Uses a small, fixed number of bins

## Radix Example

- Keys: 0 to 99
- Radix (base): 10
- Pass 1: Sort by units digit (modulo 10)
- Pass 2: Sort by tens digit (divide by 10)
- Result: Fully sorted list

## Radix Sort Complexity

- $k$ digits, $n$ records, radix $r$
- Time: $\Theta(k \cdot (n + r))$
- $k$ is the number of digits required to represent the max key
- Efficient when $r$ is large enough to keep $k$ small

## Array-based Radix Sort

- Avoids linked lists for better performance
- Uses a count array to determine bin boundaries
- Two passes per digit:
  1. Count occurrences of each digit
  2. Place records into auxiliary array
- Copy back to original array after each pass

## Radix Sort Analysis

- If $n$ unique keys exist, $k \geq \log_r n$
- General complexity: $O(n \log n)$
- Best performance when $r$ is large (e.g., $2^{16}$)
- Requires $n$ to be large relative to key size

## Exercise

A list of 1000 integers has keys in the range 0 to 1,000,000. Which algorithm is more efficient: Binsort or Radix Sort with base 10?

## Exercise

If you are sorting 32-bit integers, what is the minimum number of passes required using Radix Sort with a radix of $2^{16}$?
