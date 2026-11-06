---
reading: '[Heapsort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/Heapsort.html)'
teaching_goal: Students will understand the heap data structure and the heapsort algorithm.
learning_objectives:
  - Describe the heap data structure and its array representation
  - Explain the buildheap and removemax operations
  - Identify the time and space complexity of heapsort
  - Understand the advantages of heapsort for finding k-largest elements
  - Analyze the best-case performance for equal keys
---

# Heapsort

## Overview

- Based on the heap data structure
- Uses a complete binary tree
- Balanced and space efficient
- Array representation is highly efficient
- All values available at start

## Heap Properties

- Complete binary tree: filled level by level
- Max-Heap: parent $\ge$ children
- Min-Heap: parent $\le$ children
- Array mapping:
  - Parent of $i$: $\lfloor (i-1)/2 \rfloor$
  - Left child of $i$: $2i + 1$
  - Right child of $i$: $2i + 2$

## Buildheap Operation

- Transforms an arbitrary array into a heap
- Works bottom-up from the last internal node
- Time complexity: $\Theta(n)$
- Efficiently organizes data for extraction

## Removemax Operation

- Extracts the maximum element
- Swaps root with last element
- Reduces heap size
- Restores heap property (sift-down)
- Time complexity: $\Theta(\log n)$

## Heapsort Algorithm

- Step 1: Build a MaxHeap from the array
- Step 2: Repeatedly remove the maximum
- Step 3: Place maximum at the end of the array
- Step 4: Repeat until array is sorted

## Implementation

```cpp
void heapsort(int A[], int n) {
  MaxHeap H(A, n, n);
  for (int i = 0; i < n; i++) {
    H.removemax();
  }
}
```

## Complexity Analysis

- Time: $O(n \log n)$ (Best, Average, Worst)
- Space: $O(1)$ (In-place)
- Comparison: Slower than Quicksort by constant factor
- Advantage: Guaranteed $O(n \log n)$ performance

## Special Case: k-Largest

- Find $k$ largest elements
- Build heap: $O(n)$
- Extract $k$ times: $O(k \log n)$
- Total: $O(n + k \log n)$
- Significant improvement if $k \ll n$

## Best Case: Equal Keys

- All records have same key
- Removemax becomes $O(1)$
- Total time: $O(n)$
- Best-case performance for identical values

## Exercise

If an array has 100 elements, what is the time complexity to find the 5 largest elements using Heapsort?
