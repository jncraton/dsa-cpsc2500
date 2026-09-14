#include <print>

int main() {
  int size = 5;
  int* arr = static_cast<int*>(std::malloc(size * sizeof(int)));

  for (int i = 0; i < size; i++) {
    arr[i] = i * 10;
  }

  std::println("Value at index 2: {}", arr[2]);
  std::free(arr);
  return 0;
}
