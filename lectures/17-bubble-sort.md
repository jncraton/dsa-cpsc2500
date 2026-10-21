---
reading: '[Bubble Sort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BubbleSort.html)'
teaching_goal: Students will understand the mechanics and complexity of Bubble Sort.
learning_objectives:
  - Describe how Bubble Sort moves elements
  - Identify the time and space complexity
  - Implement Bubble Sort on a linked list
---

# Bubble Sort

## Overview

- Simple sorting algorithm
- Often taught to beginners
- No redeeming features
- Slow performance

## Mechanism

- Iterates through the list
- Compares adjacent keys
- Swaps if left is greater than right
- Largest values "bubble" to the right

---

![Bubble Sort Animation](https://upload.wikimedia.org/wikipedia/commons/3/37/Bubble_sort_animation.gif){height=540px}

## Pass Logic

- First pass moves largest to end
- Second pass ignores last element
- Each pass reduces search range
- Continues until sorted

---

> Bubble Sort is often taught to novice programmers in introductory computer science courses. This is unfortunate, because Bubble Sort has no redeeming features whatsoever.

---

<iframe width="960" height="540" src="https://www.youtube.com/embed/lyZQPjUT5B4?si=e6bLFCNEyGz-SiLj" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## Complexity

- Generally requires $n^2$ swaps

## Implementation

```cpp
#include <algorithm>
#include <print>
#include <iterator>
#include <list>

void bubblesort(std::list<int> &list) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    auto it = list.begin();
    auto next = std::next(it);
    while (next != list.end()) {
      if (*it > *next) {
        std::swap(*it, *next);
        swapped = true;
      }
      it = next;
      next = std::next(next);
    }
  }
}

int main() {
  std::list<int> data = {64, 34, 25, 12, 22, 11, 90};
  bubblesort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
```

## Exercise

Write a function to count the number of swaps performed during a bubble sort pass.

---

Why is Bubble Sort considered inefficient?
