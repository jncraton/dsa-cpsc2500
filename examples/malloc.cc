#include <print>

int main() {
  int* nums = static_cast<int*>(std::malloc(4 * sizeof(int)));

  for (int i = 0; i < 4; i++) {
    nums[i] = i*2;
  }

  std::println("{} {}", nums[0], nums[3]);
}