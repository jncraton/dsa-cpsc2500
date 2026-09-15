#include <print>

int main() {
  int a = 5;
  void *ptr = &a;

  std::println("{} {}", a, ptr);
}