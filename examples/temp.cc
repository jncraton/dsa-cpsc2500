#include <iostream>
#include <print>

int main() {
  int celsius;
  std::println("Enter C temp:");
  std::cin >> celsius;

  int fahrenheit = celsius * 1.8 + 32;

  std::println("{}", fahrenheit);

  return 0;
}
