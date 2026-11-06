---
reading: '[Heaps and Priority Queues](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/Heaps.html)'
teaching_goal: Students will understand the heap data structure and its application as a priority queue.
learning_objectives:
  - Define a heap and its properties
  - Distinguish between min heaps and max heaps
  - Explain the array representation of a complete binary tree
  - Describe heap insertion and removal mechanics
  - Analyze the time complexity of heap operations
  - Understand the build-heap algorithm and its efficiency
---

# Heaps and Priority Queues

## Priority Queues

- Collection of objects with priorities
- Next "most important" item is selected
- Example: Emergency room triage
- Example: OS job scheduling

## Limitations of Other Structures

- Normal Queue: $O(n)$ to find max
- Sorted List: $O(n)$ to insert
- BST: $O(n \log n)$ total for $n$ ops
- BST Risk: Can become unbalanced

## The Heap Data Structure

- Complete binary tree
- Partially ordered
- Relationship between node and children
- Logical view: Tree
- Physical view: Array

## Max Heap vs Min Heap

- Max Heap: Node $\ge$ children
- Min Heap: Node $\le$ children
- Root is max (Max Heap) or min (Min Heap)
- No relationship between siblings

## Array Representation

- Root at index 0
- Left child of $i$: $2i + 1$
- Right child of $i$: $2i + 2$
- Parent of $i$: $(i - 1) / 2$
- Efficient memory usage

## Heap Insertion

- Place new element at end of array
- Sift up to restore property
- Compare with parent
- Swap if new element is larger (Max Heap)
- Repeat until correct position

## Sift Down Mechanics

- Used in `removeMax` or `buildHeap`
- Compare node with children
- Swap with larger child
- Repeat until node is larger than children
- Or node becomes a leaf

## Remove Max

- Swap root with last element
- Decrease heap size
- Sift down new root
- Time complexity: $O(\log n)$

## Build Heap Algorithm

- Not just $n$ insertions
- Work from last internal node to root
- Call `siftDown` on each node
- Bottom-up construction

## Build Heap Complexity

- Sum of distances elements move
- $\sum_{i=1}^{\log n} (i-1)\frac{n}{2^i}$
- Closed-form solution: $\approx 2n$
- Complexity: $O(n)$

## Comparison: Insert vs Build

| Operation | Insertion Method | Build Method |
| --- | --- | --- |
| Strategy | Top-down | Bottom-up |
| Complexity | $O(n \log n)$ | $O(n)$ |
| Use Case | Dynamic additions | Static initialization |

## Exercise

A heap has 100 elements. What is the maximum height of the tree?

## Exercise

If you have an array of 10 elements, what is the index of the parent of the element at index 7?

## Exercise

Explain why `buildHeap` is faster than $n$ successive `insert` operations.
