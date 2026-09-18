---
teaching_goal: Students will observe and analyze the performance characteristics of std::vector operations through live measurement.
learning_objectives:
  - Identify which std::vector operations are fast and which are slow
  - Explain why certain operations (like insertion at the beginning) are costly
  - Use wall-clock time to evaluate the practical impact of data structure choices
reading: '[std::vector](https://en.cppreference.com/cpp/container/vector)'
---

# Vector Performance

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
#include <iostream>
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
  std::cout << "Time: " << diff.count() << "s\n";
  return 0;
}
```

## Exercise

Complete the code to measure how long it takes to fill a vector with 1,000,000 integers.

```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v;
  // Start timer here
  
  for (int i = 0; i < 1000000; ++i) {
    v.push_back(i);
  }

  // End timer here
  // Print result
  return 0;
}
```

## Result

- `push_back` is generally very fast
- Amortized constant time
- Most operations are efficient

## Accessing Elements

- `v[i]` provides direct access
- Constant time operation
- Very fast for reading data

## Measuring Access

```cpp
#include <iostream>
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
  std::cout << "Sum: " << sum << "\nTime: " << diff.count() << "s\n";
  return 0;
}
```

## Exercise

Modify the code to measure the time taken to access 10,000,000 elements.

## Result

- Random access is extremely fast
- The cost is independent of the size of the vector

## Inserting at End

- `push_back` adds to the end
- Fast because no shifting is needed
- Only slow when resizing occurs

## Measuring Push Back

```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000000; ++i) {
    v.push_back(i);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::cout << "Time: " << diff.count() << "s\n";
  return 0;
}
```

## Result

- `push_back` is the preferred way to grow a list
- Efficient for building collections

## Inserting at Start

- `v.insert(v.begin(), value)`
- Requires shifting all existing elements
- Very slow for large vectors

## Measuring Insert

```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1000000);
  auto start = std::chrono::high_resolution_clock::now();

  v.insert(v.begin(), 0);

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::cout << "Time: " << diff.count() << "s\n";
  return 0;
}
```

## Exercise

Measure the time taken to insert 1,000 elements at the beginning of a vector of size 100,000.

## Result

- Inserting at the front is expensive
- Cost grows linearly with vector size
- Avoid this for large datasets

## Removing from End

- `v.pop_back()`
- Removes the last element
- Fast because no shifting is needed

## Measuring Pop Back

```cpp
#include <iostream>
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
  std::cout << "Time: " << diff.count() << "s\n";
  return 0;
}
```

## Result

- `pop_back` is very efficient
- Constant time operation

## Removing from Start

- `v.erase(v.begin())`
- Requires shifting all remaining elements
- Very slow for large vectors

## Measuring Erase

```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1000000);
  auto start = std::chrono::high_resolution_clock::now();

  v.erase(v.begin());

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::cout << "Time: " << diff.count() << "s\n";
  return 0;
}
```

## Exercise

Measure the time taken to erase 100 elements from the beginning of a vector of size 100,000.

## Result

- Erasing from the front is expensive
- Cost grows linearly with vector size
- Use a different structure if front-removal is frequent

## Summary of Costs

- Fast: `push_back`, `pop_back`, `v[i]`
- Slow: `insert(begin)`, `erase(begin)`

## Choosing the Right Tool

- Use `std::vector` for end-heavy operations
- Consider `std::deque` or `std::list` for front-heavy operations

## Stewardship of Resources

- Efficient code respects the user's time
- Good stewardship of CPU cycles is a form of care
- We aim to write code that serves others well

---

How might choosing the wrong data structure impact a system?

## Exercise

Write a program that measures the time difference between `push_back` and `insert(v.begin())` for a vector of 10,000 elements. Compare the results.
