---
teaching_goal: Students will observe and analyze the performance characteristics of std::list operations through live measurement.
learning_objectives:
  - Identify which std::list operations are fast and which are slow
  - Explain why certain operations (like insertion at the beginning) are efficient
  - Use wall-clock time to evaluate the practical impact of data structure choices
reading: '[std::list](https://en.cppreference.com/cpp/container/list)'
---

# List

## std::list

- The doubly linked list in C++
- Provides efficient insertion/deletion
- Does not support random access

## Reference

- [std::list Documentation](https://en.cppreference.com/cpp/container/list)

## Measuring Time

- We use wall-clock time
- Measures actual time elapsed
- Helps us see the "cost" of code

## Measuring Tool

- `std::chrono` library
- High-resolution clocks
- Captures time before and after

## Example Code

```cpp
#include <print>
#include <list>
#include <chrono>

int main() {
  std::list<int> l;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100000; ++i) {
    l.push_back(i);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
```

## Exercise

Modify the code to time the runtime for various sizes of list. How does the time change as a function of size?

## Result

- `push_back` is generally very fast
- How long does it take to add one element?
- 1 million?
- 1 billion?

## Accessing Elements

- `*it` provides access via iterator
- Not direct index access
- Requires traversal

## Measuring Access

```cpp
#include <print>
#include <list>
#include <chrono>

int main() {
  std::list<int> l(1000000);
  auto start = std::chrono::high_resolution_clock::now();

  long sum = 0;
  for (auto it = l.begin(); it != l.end(); ++it) {
    sum += *it;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Sum: {}\nTime: {}s", sum, diff.count());
  return 0;
}
```

## Result

- Traversal is linear
- The cost is proportional to the size of the list

## Inserting at End

- `push_back` adds to the end
- Fast because it only updates pointers
- Constant time operation

## Inserting at Start

- `push_front` adds to the beginning
- Fast because it only updates pointers
- Constant time operation

## Measuring Insert

```cpp
#include <print>
#include <list>
#include <chrono>

int main() {
  std::list<int> l;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1e3; i++) {
    l.push_front(1);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
```

## Exercise

Modify the code to time the runtime for various numbers of insertions. How does the time change as a function of insertions?

## Result

- Inserting at the front is very efficient
- Avoid `std::vector` for frequent front-insertions

## Removing from End

- `pop_back()`
- Removes the last element
- Fast because it only updates pointers

## Measuring Pop Back

```cpp
#include <print>
#include <list>
#include <chrono>

int main() {
  std::list<int> l(1000000);
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000000; ++i) {
    l.pop_back();
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
```

## Result

- `pop_back` is very efficient
- Constant time operation

## Removing from Start

- `pop_front()`
- Removes the first element
- Fast because it only updates pointers

---

How would you expect this to perform?

## Measuring Erase

```cpp
#include <print>
#include <list>
#include <chrono>

int main() {
  std::list<int> l;

  int n = 1e5;

  for (int i = 0; i < n; i++) {
    l.push_back(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    l.pop_front();
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
```

## Exercise

How does performance change with size?

## Result

- Erasing from the front is efficient
- Use `std::list` if front-removal is frequent

## Summary of Costs

- Fast: `push_back`, `push_front`, `pop_back`, `pop_front`
- Slow: `*it` (traversal)

## Choosing the Right Tool

- Use `std::list` for frequent front/back insertions
- Use `std::vector` for fast random access
