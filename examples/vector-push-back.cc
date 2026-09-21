#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1e9; ++i) {
    v.push_back(i);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
