---
teaching_goal: Students will understand how dynamic lists (arrays with automated resizing) bridge the gap between fixed-size arrays and flexible collections by implementing Python-like list semantics in C++.
learning_objectives:
  - Explain the difference between logical size (`size`) and physical allocation capacity (`capacity`)
  - Describe Python-like dynamic list operations (`append`, `get`, `insert`, `pop`) in C++
  - Manage dynamic memory safely using constructors, destructors, and automated resizing
reading: '[Dynamic Arrays](https://en.wikipedia.org/wiki/Dynamic_array), [Python Lists](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)'
---

# Dynamic Arrays

## Limitations of Arrays

- C arrays have fixed size
- Heap arrays can be sized at runtime, but cannot grow once allocated
- To add more items we must allocate more space, copy existing elements, and free old memory

---

## Python List Semantics

- `append`
- `__getitem__`
- `remove`
- `clear`
- `count`
- `insert`
- `pop`

## Python List Implementation

- In Python, lists grow automatically
- Users do not manage capacity or memory allocation

---

## Dynamic Array Design

- Operating systems don't generally provide auto-growing memory allocations
- We could track the `capacity` of a memory allocation and grow it as array `size` increases
- When `size == capacity`, the list automatically resizes before adding new elements

## Resize

- Increases our capacity
- Requires a new allocation and copying values

---

```cpp
void resize(int *&data, std::size_t size, std::size_t &capacity,
            std::size_t new_capacity) {
  int *new_data = new int[new_capacity];

  for (std::size_t i = 0; i < size; i++) {
    new_data[i] = data[i];
  }

  delete[] data;
  data = new_data;
  capacity = new_capacity;
}
```

## Append

- Increment `size`
- May need to call `resize`
- Places a new element at the end once we have `capacity`

---

```cpp
void append(int *&data, std::size_t &size, std::size_t &capacity, int value) {
  if (size >= capacity) {
    resize(data, size, capacity, capacity * 2);
  }

  data[size] = value;
  size++;
}
```

## Get

- Returns the element at an index
- Throws on invalid indices

---

```cpp
int get(const int *data, std::size_t size, int index) {
  if (index < 0 || static_cast<std::size_t>(index) >= size) {
    throw std::out_of_range("Index out of bounds");
  }

  return data[index];
}
```

## Remove

- Removes the first occurence of a value
- Decrements `size`

---

```cpp
void remove(int *data, std::size_t &size, int value) {
  std::size_t index = 0;

  while (index < size && data[index] != value) {
    index++;
  }

  if (index == size) {
    throw std::runtime_error("Value not found");
  }

  for (std::size_t i = index; i + 1 < size; i++) {
    data[i] = data[i + 1];
  }

  size--;
}
```

## Clear

- Sets size to zero
- Does not need to free memory or change capacity

---

```cpp
void clear(std::size_t &size) {
  size = 0;
}
```

## Count

- Counts the number of occurences of `value`
- Returns an integer count

---

```cpp
std::size_t count(const int *data, std::size_t size, int value) {
  std::size_t result = 0;

  for (std::size_t i = 0; i < size; i++) {
    if (data[i] == value) {
      result++;
    }
  }

  return result;
}
```

## Performance

- Most `append` operations are quick because there is spare capacity
- When capacity is exhausted, `resize()` takes more time
- Because capacity doubles each time, costly resizes happen infrequently

---

![Resize Performance](https://upload.wikimedia.org/wikipedia/commons/3/31/Dynamic_array.svg){height=540px}
