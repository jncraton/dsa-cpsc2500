#include <stdio.h>

int add(int a, int b) {
  return a + b;
}

float add_float(float a, float b) {
  return a + b;
}

int main() {
  float result = add_float(2, 3.5);

  printf("%d\n", result);
}