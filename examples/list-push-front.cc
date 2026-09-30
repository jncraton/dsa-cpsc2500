#include <chrono>
#include <list>
#include <print>
#include <vector>

int main() {
  constexpr int count = 100000;

  std::list<int> l;
  std::vector<int> v;

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < count; ++i) {
    l.push_front(1);
  }
  auto list_end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> list_time = list_end - start;
  std::println("std::list: {}s", list_time.count());
  
  for (int i = 0; i < count; ++i) {
    v.insert(v.begin(), 1);
  }
  auto vector_end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> vector_time = vector_end - list_end;

  std::println("std::vector: {}s", vector_time.count());

  return 0;
}
