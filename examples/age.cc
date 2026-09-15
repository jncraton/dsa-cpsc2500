#include <iostream>
#include <print>

int main() {
  int age;
  std::println("Enter your age: ");
  std::cin >> age;

  std::println("{}", age);

  if (age >= 13) {
    std::println("Welcome to the site.");
  } else {
    std::println("You must be over 13 to access this site.");
  }
  return 0;
}
