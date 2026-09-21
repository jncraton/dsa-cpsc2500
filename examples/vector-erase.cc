#include <print>
#include <vector>
#include <chrono>

int main() {
  std::vector<int> v(1);

  int n = 1e5;

  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n; i++) {
    v.erase(v.begin());
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
