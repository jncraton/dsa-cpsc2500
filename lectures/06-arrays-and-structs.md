---
teaching_goal: Students will be able to organize data using contiguous arrays and custom data types via structs.
learning_objectives:
  - Declare and initialize static and dynamic arrays
  - Map array indices to memory offsets
  - Define and instantiate structs to group related data
  - Use pointers to navigate arrays and access struct members
---

# Arrays and Structs

## Arrays

- An array is a sequential list of items
- All elements are the same type
- Elements are accessed by a zero-based index

## Static Arrays

- Allocated on the stack
- Size must be known at compile time

```cpp
#include <print>

int main() {
  int scores[5] = {90, 85, 70, 95, 80};
  std::println("First score: {}", scores[0]);
  return 0;
}
```

## Array Indexing

- Indexing is shorthand for pointer arithmetic
- `array[i]` is equivalent to `*(array + i)`

## Dynamic Arrays

- Allocated on the heap using `malloc`
- Allows the size to be determined at runtime

```cpp
#include <print>

int main() {
  int size = 5;
  int* arr = static_cast<int*>(std::malloc(size * sizeof(int)));

  for (int i = 0; i < size; i++) {
    arr[i] = i * 10;
  }

  std::println("Value at index 2: {}", arr[2]);
  std::free(arr);
  return 0;
}
```

## Structs

- Arrays group items of the same type
- Structs group items of different types
- Structs create a custom composite data type

## Defining a Struct

- Uses the `struct` keyword
- Defines a template for the data layout

```cpp
struct Student {
  int id;
  float gpa;
  char grade;
};
```

## Instantiating Structs

- Create variables of the struct type
- Access members using the dot `.` operator

```cpp
#include <print>

struct Student {
  int id;
  float gpa;
  char grade;
};

int main() {
  Student s1 = {101, 3.8, 'A'};
  std::println("Student {} has a GPA of {}", s1.id, s1.gpa);
  return 0;
}
```

## Pointers to Structs

- Pointers can store the address of a struct
- Use the arrow `->` operator to access members via a pointer

```cpp
#include <print>

struct Student {
  int id;
  float gpa;
};

int main() {
  Student s1 = {102, 3.5};
  Student* ptr = &s1;

  std::println("ID via pointer: {}", ptr->id);
  return 0;
}
```

## Arrays of Structs

- Combine arrays and structs to manage lists of objects
- Common pattern for database-like records in memory

```cpp
#include <print>

struct Point {
  int x;
  int y;
};

int main() {
  Point path[3] = {{0, 0}, {1, 5}, {2, 10}};
  
  for (int i = 0; i < 3; i++) {
    std::println("Point {}: ({}, {})", i, path[i].x, path[i].y);
  }
  return 0;
}
```

## Exercise

Define a struct called Book with a title (as a char array), an author, and a price. Create a static array of 3 Book objects on the stack and initialize them directly using brace-initialization. Print the details of each book.
