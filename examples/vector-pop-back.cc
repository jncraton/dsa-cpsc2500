#include <chrono>
#include <print>
#include <vector>

int main() {
  std::vector<int> v(1000000);
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000000; ++i) {
    v.pop_back();
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
