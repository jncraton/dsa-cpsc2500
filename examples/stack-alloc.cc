#include <print>

int main() {
  int nums[4];

  for (int i = 0; i < 4; i++) {
    nums[i] = i * 2;
  }

  std::println("{} {}", nums[0], nums[3]);
}