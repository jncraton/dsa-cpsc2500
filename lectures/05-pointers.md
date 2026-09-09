---
teaching_goal: Students will understand how C++ manages memory manually using pointers and dynamic allocation.
learning_objectives:
  - Define pointers and the address-of operator
  - Use malloc and free to allocate and deallocate memory on the heap
  - Identify the risks of memory leaks and dangling pointers
---

# Pointers and Memory

## Memory Addresses

- Every variable lives in a location in memory
- This location is an address

---

| Variable | Type | Size | Address |
|---|---|:----|---:|
| `x` | `int` | 4 bytes | `0x7FFC` |
| `letter` | `char` | 1 byte | `0x7FFB` |
| `ptr` | `int*` | 8 bytes | `0x7FF0` |

## The Address-of Operator

- The `&` operator retrieves a memory address
- It tells us "where" a value is stored

## Defining Pointers

- A pointer is a variable that stores a memory address
- It points to the location of another value

## Pointer Syntax

```cpp
#include <print>

int main() {
  int a = 5;
  void* ptr = &a;

  std::println("{} {}", a, ptr);
}
```

## Dereferencing

- The `*` operator accesses the value at an address
- It "follows" the pointer to the target

---

```cpp
#include <print>

int main() {
  int a = 5;
  void* ptr = &a;

  int b = *static_cast<int*>(ptr);

  std::println("{} {} {}", a, ptr, b);
}
```

## Stack vs Heap

- The stack is managed automatically
- The heap is a pool of memory

## Stack Allocation

```cpp
#include <print>

int main() {
  int nums[4];

  for (int i = 0; i < 4; i++) {
    nums[i] = i*2;
  }

  std::println("{} {}", nums[0], nums[3]);
}
```

## Dynamic Allocation

- `malloc` reserves memory on the heap
- It returns a `void*` which must be cast

## Using malloc

```cpp
#include <print>

int main() {
  int* nums = static_cast<int*>(std::malloc(4 * sizeof(int)));

  for (int i = 0; i < 4; i++) {
    nums[i] = i*2;
  }

  std::println("{} {}", nums[0], nums[3]);
}
```

## Leaks

- `malloc` requests resources from the system
- The program is responsible for those resources
- Unused memory remains occupied until freed

## The free Function

- `free()` releases memory back to the system
- It prevents memory leaks
- Failure to free leads to resource exhaustion

## Freeing Memory

```cpp
#include <print>

int main() {
  int* nums = static_cast<int*>(std::malloc(4 * sizeof(int)));

  for (int i = 0; i < 4; i++) {
    nums[i] = i*2;
  }

  std::println("{} {}", nums[0], nums[3]);

  std::free(nums);
}
```

## Memory Leaks

- Occur when memory is allocated but never freed
- Can cause programs to slow down or crash
- Represents a failure in resource management

## Dangling Pointers

- A pointer pointing to freed memory
- Accessing it leads to undefined behavior
- Always set pointers to `nullptr` after freeing

## Exercise

Write a program that allocates an array of 10 integers using `malloc`, fills it with the first 10 square numbers, prints them, and then frees the memory.
