---
reading: '[Merge Sort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/MergeSort.html)'
teaching_goal: Students will understand the divide and conquer strategy of Merge Sort.
learning_objectives:
  - Describe the divide and conquer strategy
  - Explain the merge step mechanics
  - Compare recursive and iterative implementations
  - Identify the time and space complexity
---

# Merge Sort

## Overview

- Divide and conquer algorithm
- Breaks problem into smaller subproblems
- Solves subproblems recursively
- Combines solutions to form final result

## Divide and Conquer

- Split array into two halves
- Sort each half recursively
- Merge sorted halves into one

## The Merge Step

- Requires two sorted subarrays
- Requires an auxiliary array
- Compares smallest elements of each
- Copies smaller element to result

## Recursive Logic

- Base case: Array of size 1
- Recursive step:
  1. Find midpoint
  2. Sort left half
  3. Sort right half
  4. Merge halves

## Recursive Implementation

```cpp
void mergesort_recursive(std::vector<int> &A, std::vector<int> &tmp, int first,
                         int last) {
  if (first >= last) return;

  unsigned int mid = first + (last - first) / 2;
  mergesort_recursive(A, tmp, first, mid);
  mergesort_recursive(A, tmp, mid + 1, last);

  unsigned int left_idx = first;
  unsigned int right_idx = mid + 1;
  unsigned int merged_idx = first;

  while (left_idx <= mid && right_idx <= last) {
    if (A[left_idx] <= A[right_idx]) {
      tmp[merged_idx] = A[left_idx];
      left_idx++;
    } else {
      tmp[merged_idx] = A[right_idx];
      right_idx++;
    }
    merged_idx++;
  }

  while (left_idx <= mid) {
    tmp[merged_idx] = A[left_idx];
    left_idx++;
    merged_idx++;
  }

  while (right_idx <= last) {
    tmp[merged_idx] = A[right_idx];
    right_idx++;
    merged_idx++;
  }

  for (unsigned int m = first; m <= last; ++m) {
    A[m] = tmp[m];
  }
}
```

---

How does the recursion depth relate to the array size?

## Iterative Logic

- Bottom-up approach
- Starts with subarrays of size 1
- Merges into size 2, 4, 8...
- Eliminates recursion stack overhead
- More complex to implement correctly

## Iterative Implementation

```cpp
void mergesort(std::vector<int> &A) {
  int total_size = static_cast<int>(A.size());
  if (total_size < 2) return;

  std::vector<int> tmp(total_size);

  for (int block_size = 1; block_size < total_size; block_size *= 2) {
    for (int block_start = 0; block_start < total_size;
         block_start += 2 * block_size) {
      int mid_point = std::min(block_start + block_size, total_size);
      int block_end = std::min(block_start + 2 * block_size, total_size);

      int left_ptr = block_start;
      int right_ptr = mid_point;
      int merged_ptr = block_start;

      while (left_ptr < mid_point && right_ptr < block_end) {
        if (A[left_ptr] <= A[right_ptr]) {
          tmp[merged_ptr] = A[left_ptr];
          left_ptr++;
        } else {
          tmp[merged_ptr] = A[right_ptr];
          right_ptr++;
        }
        merged_ptr++;
      }

      while (left_ptr < mid_point) {
        tmp[merged_ptr] = A[left_ptr];
        left_ptr++;
        merged_ptr++;
      }

      while (right_ptr < block_end) {
        tmp[merged_ptr] = A[right_ptr];
        right_ptr++;
        merged_ptr++;
      }

      for (int current_idx = block_start; current_idx < block_end;
           ++current_idx) {
        A[current_idx] = tmp[current_idx];
      }
    }
  }
}
```

## Complexity Analysis

- Time: $O(n \log n)$
- Best/Average/Worst case: $O(n \log n)$
- Space: $O(n)$ for auxiliary array
- Stable sort: Yes

## Comparison

| Feature | Recursive | Iterative |
| --- | --- | --- |
| Strategy | Top-down | Bottom-up |
| Stack Usage | $O(\log n)$ | $O(1)$ |
| Complexity | $O(n \log n)$ | $O(n \log n)$ |
| Readability | High | Moderate |
