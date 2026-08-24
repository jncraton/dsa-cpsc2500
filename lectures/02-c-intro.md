---
teaching_goal: Students will be able to write, compile, and run basic C programs using gcc to perform simple arithmetic and logic.
learning_objectives:
  - Compile and run a C program using gcc
  - Declare and use basic data types (int, float, char)
  - Implement conditional logic using if-else
  - Use for-loops to iterate a set number of times
  - Define and call functions to modularize code
reading: '[Hello World](https://en.wikibooks.org/wiki/C_programming/Intro_exercise)'
---

# C Programming

## Compilation

- `gcc -o program main.c`
- `-o` specifies the output name

## Execution

- `./program`
- Runs the compiled binary

## Hello World

```c
#include <stdio.h>

int main() {
  printf("Hello, world\n");
  return 0;
}
```

## Basic Types

- `int`: Whole numbers
- `float`: Decimal numbers
- `char`: Single characters

## Variable Declaration

- Types must precede names
- Semicolons terminate statements

```c
int age = 25;
float price = 9.99;
char grade = 'A';
```

## Printing Values

- `%d`: Integer
- `%f`: Float
- `%c`: Character

```c
printf("Age: %d\n", age);
printf("Price: %.2f\n", price);
```

## Conditionals

- `if` statements check truth
- `else` handles alternative paths

```c
if (age >= 18) {
  printf("Adult\n");
} else {
  printf("Minor\n");
}
```

## Boolean Logic

- `==`: Equal to
- `!=`: Not equal
- `&&`: And
- `||`: Or

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

## Exercise

Create a program that asks the user for a number and prints whether it is positive, negative, or zero.
