#include <cassert>
#include <cstddef>
#include <stdexcept>

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

void append(int *&data, std::size_t &size, std::size_t &capacity, int value) {
  if (size >= capacity) {
    resize(data, size, capacity, capacity * 2);
  }

  data[size] = value;
  size++;
}

int get(const int *data, std::size_t size, int index) {
  if (index < 0 || static_cast<std::size_t>(index) >= size) {
    throw std::out_of_range("Index out of bounds");
  }

  return data[index];
}

void pop(std::size_t &size) {
  if (size > 0) {
    size--;
  }
}

void insert(int *&data, std::size_t &size, std::size_t &capacity,
            int index, int value) {
  if (index < 0 || static_cast<std::size_t>(index) > size) {
    throw std::out_of_range("Index out of bounds");
  }

  if (size >= capacity) {
    resize(data, size, capacity, capacity * 2);
  }

  for (std::size_t i = size; i > static_cast<std::size_t>(index); i--) {
    data[i] = data[i - 1];
  }

  data[index] = value;
  size++;
}

int main() {
  std::size_t capacity = 4;
  std::size_t size = 0;
  int *data = new int[capacity];

  append(data, size, capacity, 1);
  assert(size == 1);
  assert(get(data, size, 0) == 1);

  append(data, size, capacity, 2);
  assert(get(data, size, 0) == 1);
  assert(get(data, size, 1) == 2);

  try {
    get(data, size, 2);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &) {
  }

  pop(size);
  assert(get(data, size, 0) == 1);
  assert(size == 1);

  pop(size);
  assert(size == 0);

  append(data, size, capacity, 1);
  append(data, size, capacity, 2);

  insert(data, size, capacity, 0, 0);
  assert(get(data, size, 0) == 0);
  assert(get(data, size, 1) == 1);
  assert(get(data, size, 2) == 2);

  insert(data, size, capacity, 1, 100);
  assert(get(data, size, 1) == 100);

  insert(data, size, capacity, 2, 200);
  assert(get(data, size, 2) == 200);

  delete[] data;
}
