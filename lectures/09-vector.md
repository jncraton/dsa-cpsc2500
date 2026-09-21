---
teaching_goal: Students will observe and analyze the performance characteristics of std::vector operations through live measurement.
learning_objectives:
  - Identify which std::vector operations are fast and which are slow
  - Explain why certain operations (like insertion at the beginning) are costly
  - Use wall-clock time to evaluate the practical impact of data structure choices
reading: '[std::vector](https://en.cppreference.com/cpp/container/vector)'
---

# Vector

## std::vector

- The standard dynamic array in C++
- Provides efficient random access
- Automatically manages memory

## Reference

- [std::vector Documentation](https://en.cppreference.com/cpp/container/vector)

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
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100000; ++i) {
    v.push_back(i);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
```

## Exercise

Modify the code to time the runtime for various sizes of vector. How does the time change as a function of size?

## Result

- `push_back` is generally very fast
- How long does it take to add one element?
- 1 million?
- 1 billion?

## Accessing Elements

- `v[i]` provides direct access
- Very fast for reading data

## Measuring Access

```cpp
#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1000000);
  auto start = std::chrono::high_resolution_clock::now();

  long sum = 0;
  for (int i = 0; i < 1000000; ++i) {
    sum += v[i];
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Sum: {}\nTime: {}s", sum, diff.count());
  return 0;
}
```

## Result

- Random access is extremely fast
- The cost is independent of the size of the vector

## Inserting at End

- `push_back` adds to the end
- Fast because no shifting is needed
- Only slow when resizing occurs

## Inserting at Start

- `v.insert(v.begin(), value)`

## Measuring Insert

```cpp
#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1);
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1e3; i++) {
    v.insert(v.begin(), 1);
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

- Inserting at the front is expensive
- Avoid this for large datasets

## Removing from End

- `v.pop_back()`
- Removes the last element
- Fast because no shifting is needed

## Measuring Pop Back

```cpp
#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1000000);
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000000; ++i) {
    v.pop_back();
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

- `v.erase(v.begin())`

---

How would you expect this to perform?

## Measuring Erase

```cpp
#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1);

  int n = 1e5;

  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    v.erase(v.begin());
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

- Erasing from the front is expensive
- Use a different structure if front-removal is frequent

## Summary of Costs

- Fast: `push_back`, `pop_back`, `v[i]`
- Slow: `insert(begin)`, `erase(begin)`

## Choosing the Right Tool

- Use `std::vector` for end-heavy operations
- Consider an alternative for front-heavy operations

---

How might choosing the wrong data structure impact a system?
