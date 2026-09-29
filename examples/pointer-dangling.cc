#include <print>

int main() {
  int *ptr = new int(10);

  std::println("Value: {}", *ptr);
  delete ptr;
  std::println("Value: {}", *ptr);
}
