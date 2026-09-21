#include <print>

int main() {
  int scores[5] = {90, 85, 70, 95, 80};

  int i = 0;

  while (1) {
    std::println("Next score: {}", *(scores + i));
    i++;
  }
  return 0;
}