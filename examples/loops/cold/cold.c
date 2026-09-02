#include <stdio.h>

/*
Sample input

3
5 -10 15
*/

int main() {
  int negatives = 0;
  int total_temps;

  scanf("%d", &total_temps);

  for (int i = 0; i < total_temps; i++) {
    int current_temp;

    scanf("%d", &current_temp);

    if (current_temp < 0) {
      negatives += 1;
    }
  }

  printf("%d\n", negatives);
}