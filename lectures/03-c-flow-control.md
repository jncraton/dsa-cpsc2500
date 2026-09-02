---
reading: '[C Flow Control](https://en.wikibooks.org/wiki/C_programming/Program_flow_control), [C Functions](https://en.wikibooks.org/wiki/C_programming/Procedures_and_functions)'
---

# C Loops and Functions

## Loops

- `for` loops repeat code
- Useful for counting

```c
for (int i = 0; i < 5; i++) {
  printf("Count: %d\n", i);
}
```

## Functions

- Reusable blocks of code
- Must specify return type

```c
int add(int a, int b) {
  return a + b;
}
```

## Function Calls

- Pass arguments to functions
- Receive the returned value

```c
int main() {
  int result = add(5, 10);
  printf("Sum: %d\n", result);
  return 0;
}
```

## Example Program

```c
#include <stdio.h>

int main() {
  int count = 3;
  for (int i = 1; i <= count; i++) {
    if (i % 2 == 0) {
      printf("Even: %d\n", i);
    } else {
      printf("Odd: %d\n", i);
    }
  }
  return 0;
}
```

## Problems

- <https://open.kattis.com/problems/cold>
- <https://open.kattis.com/problems/different>
- <https://open.kattis.com/problems/abc>
