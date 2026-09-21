#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1);
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1e3; i++) {
    v.insert(v.begin(), 1);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
