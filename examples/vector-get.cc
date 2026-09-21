#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1e9);
  auto start = std::chrono::high_resolution_clock::now();

  long sum = 0;
  for (int i = 0; i < 1e9; ++i) {
    sum += v[i];
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Sum: {}\nTime: {}s", sum, diff.count());
  return 0;
}
