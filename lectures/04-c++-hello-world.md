---
teaching_goal: Students will be able to write a basic C++ program that handles user input and simple conditional logic.
learning_objectives:
  - Write a "Hello World" program in C++
  - Capture and store user input using cin
  - Evaluate conditions using if statements
  - Compile and run C++ code using the gcc/g++ compiler
---

# C++ Basics

## Hello World

```cpp
#include <print>

int main() {
  std::println("Hello, world!");
  return 0;
}
```

## Understanding println

- Part of the modern C++ library
- Simplifies output compared to older methods
- Handles newlines automatically

## Compilation

- Use the `g++` command
- Tells the computer how to build the code

## Build Command

```bash
g++ -std=c++23 hello.cc -o hello
```

## Running Code

- Execute the output file
- The `./` prefix runs the current directory

## Run Command

```bash
./hello
```

## User Input

- Programs can interact with users
- `std::cin` captures data from the keyboard

## Input Example

```cpp
int age;
std::cin >> age;
```

## Conditionals

- `if` statements allow for choices
- Code only runs if a condition is true

## Conditional Example

```cpp
if (age >= 18) {
  std::println("You are an adult");
} else {
  std::println("You are a minor");
}
```

## Full Example

```cpp
#include <iostream>

int main() {
  int age;
  std::cout << "Enter your age: ";
  std::cin >> age;

  if (age >= 18) {
    std::println("Welcome to the site.");
  } else {
    std::println("Access denied.");
  }
  return 0;
}
```

## Exercise

Write a program that asks for a temperature in Celsius. Convert to Farenheit and print the result.
