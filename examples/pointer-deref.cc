#include <print>

int main() {
  int a = 5;
  void *ptr = &a;

  int b = *static_cast<int *>(ptr);

  std::println("{} {} {}", a, ptr, b);
}