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

void clear(std::size_t &size) {
  size = 0;
}

std::size_t count(const int *data, std::size_t size, int value) {
  std::size_t result = 0;

  for (std::size_t i = 0; i < size; i++) {
    if (data[i] == value) {
      result++;
    }
  }

  return result;
}

int main() {
  std::size_t capacity = 4;
  std::size_t size = 0;
  int *data = new int[capacity];

  append(data, size, capacity, 1);
  assert(size == 1);
  assert(get(data, size, 0) == 1);

  append(data, size, capacity, 2);
  assert(size == 2);
  assert(get(data, size, 0) == 1);
  assert(get(data, size, 1) == 2);

  try {
    get(data, size, 2);
    assert(false && "Should have thrown out_of_range");
  } catch (const std::out_of_range &) {
  }

  append(data, size, capacity, 0);
  append(data, size, capacity, 100);
  append(data, size, capacity, 200);
  append(data, size, capacity, 2);
  append(data, size, capacity, 2);

  assert(size == 7);
  assert(get(data, size, 0) == 1);
  assert(get(data, size, 1) == 2);
  assert(get(data, size, 2) == 0);
  assert(get(data, size, 3) == 100);
  assert(get(data, size, 4) == 200);
  assert(get(data, size, 5) == 2);
  assert(get(data, size, 6) == 2);

  assert(count(data, size, 2) == 3);
  assert(count(data, size, 100) == 1);

  remove(data, size, 2);
  assert(size == 6);
  assert(count(data, size, 2) == 2);
  assert(get(data, size, 0) == 1);
  assert(get(data, size, 1) == 0);
  assert(get(data, size, 2) == 100);
  assert(get(data, size, 3) == 200);
  assert(get(data, size, 4) == 2);
  assert(get(data, size, 5) == 2);

  try {
    remove(data, size, 999);
    assert(false && "Should have thrown when value was not found");
  } catch (const std::runtime_error &) {
  }

  clear(size);
  assert(size == 0);
  assert(count(data, size, 2) == 0);

  delete[] data;
}
