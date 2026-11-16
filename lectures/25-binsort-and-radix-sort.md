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

---

<iframe width="960" height="540" src="https://www.youtube.com/embed/m4yVlPqeZwo?si=G837NilK_vmIMUhW&amb;start=1364" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

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
- Complexity: $O(n + MaxKeyValue)$

---

```cpp
#include <print>
#include <vector>
#include <algorithm>

void binsort(std::vector<int>& A) {
  int max_val = 0;
  for (int x : A) {
    if (x > max_val) max_val = x;
  }

  std::vector<std::vector<int>> bins(max_val + 1);
  for (int x : A) {
    bins[x].push_back(x);
  }

  int idx = 0;
  for (int i = 0; i <= max_val; ++i) {
    for (int x : bins[i]) {
      A[idx++] = x;
    }
  }
}

int main() {
  std::vector<int> data = {5, 2, 9, 1, 5, 6};
  binsort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
```

## Binsort Limitations

- Performance degrades as $MaxKeyValue$ grows
- If $MaxKeyValue = n^2$, complexity is $O(n^2)$
- Large key ranges require massive memory for bins
- Not practical for large, sparse key ranges

---

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
- Time: $O(k \cdot (n + r))$
- $k$ is the number of digits required to represent the max key
- Efficient when $r$ is large enough to keep $k$ small

## Array-based Radix Sort

- Uses a count array to determine bin boundaries
- Two passes per digit:
  1. Count occurrences of each digit
  2. Place records into auxiliary array
- Copy back to original array after each pass

---

```cpp
#include <print>
#include <vector>
#include <algorithm>
#include <cmath>

void radix_sort(std::vector<int>& A) {
  if (A.empty()) return;

  int max_val = 0;
  for (int x : A) {
    if (x > max_val) max_val = x;
  }

  int exp = 1;
  while (max_val / exp > 0) {
    std::vector<int> output(A.size());
    std::vector<int> count(10, 0);

    for (size_t i = 0; i < A.size(); ++i) {
      count[(A[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
      count[i] += count[i - 1];
    }

    for (int i = A.size() - 1; i >= 0; --i) {
      output[count[(A[i] / exp) % 10] - 1] = A[i];
      count[(A[i] / exp) % 10]--;
    }

    A = output;
    exp *= 10;
  }
}

int main() {
  std::vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};
  radix_sort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
```

---

A list of 1000 integers has keys in the range 0 to 1,000,000. Which algorithm is more efficient: Binsort or Radix Sort with base 10?

---

If you are sorting 32-bit integers, what is the minimum number of passes required using Radix Sort with a radix of $2^{16}$?
