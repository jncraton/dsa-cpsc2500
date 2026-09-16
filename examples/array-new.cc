#include <print>

int main() {
  int size = 5;
  int *arr = new int[size];

  for (int i = 0; i < size; i++) {
    arr[i] = i * 10;
  }

  std::println("Value at index 2: {}", arr[2]);
  delete[] arr;
  return 0;
}
