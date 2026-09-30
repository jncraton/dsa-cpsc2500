#include <chrono>
#include <list>
#include <print>

std::chrono::duration<double> bench(int size) {
  std::list<int> l;
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < size; ++i) {
    l.push_back(i);
  }

  auto end = std::chrono::high_resolution_clock::now();
  return end - start;
}

int main() {
  for (int i = 1000; i <= 100000000; i *= 10) {
    std::println("Time: {}s Length: {}", bench(i), i);
  }
  return 0;
}
