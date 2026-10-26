---
reading: '[Selection Sort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/SelectionSort.html)'
teaching_goal: Students will understand the mechanics and complexity of Selection Sort.
learning_objectives:
  - Describe how Selection Sort selects the largest key
  - Identify the time and space complexity
  - Implement Selection Sort on an array
---

# Selection Sort

## Overview

- Simple sorting algorithm
- Inspired by sorting physical objects
- Selects the largest key
- Places it at the end of the list

## Analogy

- Imagine sorting phone bills
  1. Look through the pile
  2. Find the bill for December
  3. Pull it out and place it at the end
  4. Repeat for all months

## Mechanism

- Iterates through the list
- Finds the largest key in the unsorted portion
- Swaps it with the last element of that portion
- Reduces the unsorted portion size

---

## Implementation

```cpp
#include <algorithm>
#include <print>
#include <vector>

void selsort(std::vector<int> &A) {
  for (int i = 0; i < A.size() - 1; i++) {
    int bigindex = 0;
    for (int j = 1; j < A.size() - i; j++) {
      if (A[j] > A[bigindex]) {
        bigindex = j;
      }
    }
    std::swap(A[bigindex], A[A.size() - i - 1]);
  }
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
  selsort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
```

## Performance Notes

- Few record swaps
- $n-1$ total swaps
- $n^2$ comparisons
- Simple to implement

---

Why does Selection Sort perform fewer swaps than Bubble Sort?
