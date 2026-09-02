#include <stdio.h>

int main() {
  int count = 10;
  
  for (int i = 1; i <= count; i++) {
    if (i % 2 == 0) {
      printf("Even: %d\n", i);
    } else {
      printf("Odd: %d\n", i);
    }
  }
  return 0;
}