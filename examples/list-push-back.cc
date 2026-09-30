#include <print>
#include <list>
#include <chrono>

int main() {
  std::list<int> l;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 10000000; ++i) {
    l.push_back(i);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Time: {}s", diff.count());
  return 0;
}
