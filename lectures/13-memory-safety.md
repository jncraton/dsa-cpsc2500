---
teaching_goal: Students will understand the fundamentals of memory management in C++, specifically focusing on manual memory management, common pitfalls like leaks and dangling pointers, and modern safety features.
learning_objectives:
  - Explain the difference between stack and heap allocation
  - Identify and prevent memory leaks in C++
  - Understand the dangers of dangling pointers
  - Use RAII and smart pointers to automate memory management
  - Analyze a program to detect memory leaks
---

# Dates

- No class tomorrow (attend the career fair)
- Exam next Tuesday (October 6th)

# Memory Safety

---

We have been using `new` and `delete` to manage nodes in our linked lists.

What happens if we forget to `delete`? What happens if we `delete` twice?

---

## Stack vs Heap

- Stack: Automatic allocation and deallocation
- Heap: Manual allocation and deallocation
- Stack is faster and managed by the compiler
- Heap is larger and managed by the programmer

## Allocation

- `int x = 10;` (Stack)
- `int* ptr = new int(10);` (Heap)

---

## Memory Leaks

- Occur when heap memory is no longer reachable but not freed
- The memory remains "reserved" until the program ends
- Can lead to exhaustion of system resources

## Example Leak

```cpp
void leakMemory() {
  int* ptr = new int(42);
}
```

## Measuring Memory Leak

```cpp
#include <print>
#include <sys/resource.h>

long peak_memory_kb() {
  rusage usage{};
  getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss;
}

void leakMemory() { int *ptr = new int(42); }

int main() {
  for (int i = 0; i <= 10000000; ++i) {
    leakMemory();

    if (i % 1000000 == 0) {
      std::println("After {} calls: {} kB peak memory", i, peak_memory_kb());
    }
  }

  return 0;
}
```

## Dangling Pointers

- A pointer that points to memory that has been freed
- Accessing it leads to undefined behavior
- Can cause crashes or security vulnerabilities

## Example Dangling Pointer

```cpp
#include <print>

int main() {
  int* ptr = new int(10);

  std::println("Value: {}", *ptr);
  delete ptr;
  std::println("Value: {}", *ptr);
}```

---

## Manual Management

- Every `new` must have a corresponding `delete`
- Order of deletion matters (delete children before parents)
- Use `nullptr` to reset pointers after deletion

## Best Practice

```cpp
delete ptr;
ptr = nullptr;
```

---

## RAII

- Resource Acquisition Is Initialization
- Bind resource lifetime to object lifetime
- When the object goes out of scope, the destructor frees the resource

## RAII Pattern

```cpp
#include <print>

class IntValue {
public:
  explicit IntValue(int value) : value_(new int(value)) {}

  ~IntValue() { delete value_; }

  IntValue(const IntValue &) = delete;
  IntValue &operator=(const IntValue &) = delete;

  int get() const { return *value_; }

private:
  int *value_;
};

int main() {
  IntValue value(42);
  std::println("Value: {}", value.get());
}
```

## Smart Pointers

- `std::unique_ptr`: Sole ownership
- `std::shared_ptr`: Shared ownership
- `std::weak_ptr`: Non-owning reference

---

## Smart Pointer Example

```cpp
#include <memory>
#include <iostream>

void smartPointerExample() {
  std::unique_ptr<int> ptr = std::make_unique<int>(42);
  std::println("Value: {}", *ptr);
}
```

## Leaky List Operation

```cpp
#include <print>
#include <sys/resource.h>
#include <vector>

long peak_memory_kb() {
  rusage usage{};
  getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss;
}

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

void leakyRemove(Node *&head, int value) {
  if (head == nullptr)
    return;

  if (head->data == value) {
    Node *temp = head;
    head = head->next;
    return;
  }

  Node *curr = head;
  while (curr->next != nullptr && curr->next->data != value) {
    curr = curr->next;
  }

  if (curr->next != nullptr) {
    Node *temp = curr->next;
    curr->next = curr->next->next;
  }
}

int main() {
  Node *head = nullptr;

  for (int i = 0; i < 10000000; ++i) {
    head = new Node(42);
    head->next = new Node(84);
    leakyRemove(head, 84);
    leakyRemove(head, 42);

    if (i % 1000000 == 0) {
      std::println("{} kB memory reserved", peak_memory_kb());
    }
  }

  return 0;
}
```

---

## Analysis

- The `leakyRemove` function removes a node from the list
- It updates the pointers correctly
- It fails to call `delete` on the removed node

---

## Exercise

Modify the `leakyRemove` function to be memory-safe.
