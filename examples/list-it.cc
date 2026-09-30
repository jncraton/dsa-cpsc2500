#include <chrono>
#include <list>
#include <print>

int main() {
  std::list<int> l(10000000);
  auto start = std::chrono::high_resolution_clock::now();

  long sum = 0;
  for (auto it = l.begin(); it != l.end(); ++it) {
    sum += *it;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::println("Sum: {}\nTime: {}s", sum, diff.count());
  return 0;
}
