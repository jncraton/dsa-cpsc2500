---
teaching_goal: Students will understand how dynamic lists (arrays with automated resizing) bridge the gap between fixed-size arrays and flexible collections by implementing Python-like list semantics in C++.
learning_objectives:
  - Explain the difference between logical size (`size`) and physical allocation capacity (`capacity`)
  - Describe Python-like dynamic list operations (`append`, `get`, `insert`, `pop`) in C++
  - Manage dynamic memory safely using constructors, destructors, and automated resizing
reading: '[Dynamic Arrays](https://en.wikipedia.org/wiki/Dynamic_array), [Python Lists](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)'
---

# Dynamic Lists

## Limitations of Static & Fixed Dynamic Arrays

- C arrays have fixed size
- Heap arrays can be sized at runtime, but cannot grow once allocated
- To add more items we must allocate more space, copy existing elements, and free old memory

---

## Python List Semantics

- `append`
- `__getitem__`
- `insert`
- `pop`

## Python List Implementation

- In Python, lists grow automatically
- Users do not manage capacity or memory allocation

---

## Dynamic Array Design

- An `ArrayList` class encapsulates a heap array pointer, current `size`, and allocated `capacity`
- When `size == capacity`, the list automatically resizes before adding new elements

---

```cpp
#include <cassert>
#include <print>
#include <stdexcept>

class ArrayList {
private:
  int *data;
  size_t capacity;
  size_t size;

  void resize(size_t new_capacity) {
    int *new_data = new int[new_capacity];
    for (size_t i = 0; i < size; i++) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
  }

public:
  ArrayList() : capacity(4), size(0) {
    data = new int[capacity];
  }

  ~ArrayList() {
    delete[] data;
  }

  size_t get_size() const {
    return size;
  }
};
```

## Performance

- Most `append` operations are quick because there is spare capacity.
- When capacity is exhausted, `resize()` takes more time
- Because capacity doubles each time, costly resizes happen infrequently
