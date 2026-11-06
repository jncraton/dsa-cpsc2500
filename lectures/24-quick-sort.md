---
reading: '[Quicksort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/Quicksort.html)'
teaching_goal: Students will understand the divide and conquer strategy of Quicksort.
learning_objectives:
  - Describe the pivot selection and partitioning strategy
  - Explain the mechanics of the partition step
  - Identify the time and space complexity
  - Understand the impact of pivot selection on performance
---

# Quicksort

## Overview

- Divide and conquer algorithm
- Faster than Mergesort in average case
- Space efficient (in-place)
- Widely used in standard libraries (e.g., UNIX qsort)

## Divide and Conquer

- Select a value called the pivot
- Partition the array into two sublists:
  - Values less than the pivot
  - Values greater than or equal to the pivot
- Recursively sort the resulting subarrays

## The Partition Step

- Rearranges elements around a pivot
- Pivot is moved to its final sorted position
- Elements to the left are smaller
- Elements to the right are larger
- Does not require auxiliary array (unlike Mergesort)

## Pivot Selection

- Simple: Use first, middle, or last element
- Problem: Sorted/reverse-sorted inputs lead to $O(n^2)$
- Improvement: Random selection or "median of three"
- Middle element is a common, cheap compromise

---

![Quicksort Animation](https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif){height=540px}

---

<iframe width="960" height="540" src="https://www.youtube.com/embed/ywWBy6J5gz8?si=9ttGl8LInwC8RBD4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## Recursive Implementation

```cpp
void quicksort_recursive(std::vector<int> &A, int first, int last) {
  // Base case: 0 or 1 item already "sorted"
  if (first >= last) {
    return;
  }

  // Choose a pivot (middle element)
  int pivot = A[first + (last - first) / 2];
  
  // Partitioning logic
  int i = first;
  int j = last;

  while (i <= j) {
    while (A[i] < pivot) {
      i++;
    }
    while (A[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(A[i], A[j]);
      i++;
      j--;
    }
  }

  // Recursive calls on the partitioned halves
  quicksort_recursive(A, first, j);
  quicksort_recursive(A, i, last);
}

void quicksort(std::vector<int> &A) {
  if (A.empty()) {
    return;
  }

  quicksort_recursive(A, 0, static_cast<int>(A.size()) - 1);
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};

  quicksort(data);

  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
```

## Complexity Analysis

- Time: $O(n \log n)$ average
- Time: $O(n^2)$ worst case (poor pivot selection)
- Space: $O(\log n)$ for recursion stack

## Optimizations

- Small Subarrays: Use Insertion Sort for subarrays smaller than a threshold (e.g., 10-15 elements)
- Iterative Approach: Use an explicit stack to avoid recursion overhead
- Median of Three: Pick the median of first, middle, and last elements as pivot

## Comparison

| Feature | Quicksort | Mergesort |
| --- | --- | --- |
| Strategy | Partitioning | Merging |
| Space Complexity | $O(\log n)$ | $O(n)$ |
| Average Time | $O(n \log n)$ | $O(n \log n)$ |
| Worst Case Time | $O(n^2)$ | $O(n \log n)$ |
| Stability | Not Stable | Stable |
