---
reading: '[Insertion Sort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/InsertionSort.html)'
teaching_goal: Students will understand the mechanics and complexity of Insertion Sort.
learning_objectives:
  - Describe how Insertion Sort builds a sorted list
  - Identify the time and space complexity
  - Implement Insertion Sort on an array
---

# Insertion Sort

## Overview

- Simple sorting algorithm
- Inspired by sorting physical objects
- Builds a sorted sub-list
- Efficient for nearly sorted data

## Analogy

- Imagine sorting phone bills
- Look at first two bills
- Put them in order
- Take third bill
- Insert into correct position
- Repeat for all bills

## Mechanism

- Iterates through the list
- Takes current record
- Compares with preceding records
- Moves left until correct spot
- Maintains sorted prefix

## Implementation

```cpp
#include <algorithm>
#include <print>
#include <vector>

void inssort(std::vector<int> &A) {
  for (int i = 1; i < A.size(); i++) {
    for (int j = i; j > 0 && A[j] < A[j - 1]; j--) {
      std::swap(A[j], A[j - 1]);
    }
  }
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
  inssort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
```

## Complexity

- Between n and n^2 depending on original list

## Performance Notes

- Good for small arrays
- Good for nearly sorted data
- Simple to implement
- Low constant factors

---

Why is Insertion Sort efficient for nearly sorted lists?
