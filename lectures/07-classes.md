---
teaching_goal: Students will be able to define and use C++ classes to encapsulate data and behavior with access control and constructors.
learning_objectives:
  - Define a class using the `class` keyword
  - Understand and use access specifiers (`public` and `private`)
  - Implement member functions (methods) inside and outside classes
  - Create and use constructors for object initialization
  - Instantiate objects on the stack and heap
reading: '[Classes and Objects](https://en.cppreference.com/w/cpp/language/classes)'
---

# Classes

## Structs

- C structs group data together, but lack built-in behavior and access control
- C++ classes combine data and functions
- Classes provide data encapsulation and abstraction

## Defining a Class

- Uses the `class` keyword
- Members are `private` by default in classes (unlike `struct` where members are `public`)

---

```cpp
class Rectangle {
private:
  int width;
  int height;

public:
  void setDimensions(int w, int h) {
    width = w;
    height = h;
  }

  int area() {
    return width * height;
  }
};
```

## Access Specifiers

- Protect internal state from invalid modifications
- `private` is accessible only from within member functions of the same class
- `public` is accessible from outside the class

## Instantiating Objects

- Creating an instance of a class is called instantiation
- Objects can be created on the stack or heap

---

```cpp
#include <print>

class Rectangle {
private:
  int width;
  int height;

public:
  void setDimensions(int w, int h) {
    width = w;
    height = h;
  }

  int area() {
    return width * height;
  }
};

int main() {
  Rectangle rect;
  rect.setDimensions(5, 10);
  std::println("Area: {}", rect.area());
  return 0;
}
```

## Constructors

- Special member functions called automatically when an object is created
- Same name as the class, no return type
- Used to initialize member variables safely

---

```cpp
class Rectangle {
private:
  int width;
  int height;

public:
  // Constructor
  Rectangle(int w, int h) {
    width = w;
    height = h;
  }

  int area() {
    return width * height;
  }
};
```

## Member Initialization Lists

- Shorter than assignment inside the constructor body
- Syntax: 

```cpp
Constructor(args) : member1(val1), member2(val2) {}
```

---

```cpp
#include <print>

class Rectangle {
private:
  int width;
  int height;

public:
  Rectangle(int w, int h) : width(w), height(h) {}

  int area() {
    return width * height;
  }
};

int main() {
  Rectangle rect(4, 6);
  std::println("Area: {}", rect.area());
  return 0;
}
```

## `this` Pointer

- Every object has access to its own address through the `this` pointer
- Used to resolve name conflicts between member variables and parameters

---

```cpp
class Rectangle {
private:
  int width;
  int height;

public:
  Rectangle(int width, int height) {
    this->width = width;
    this->height = height;
  }
};
```

## Exercise

Create a `Spacecraft` class with private attributes for `id` (int), `fuelLevel` (float). Provide a constructor using a member initialization list and a public method `burnFuel(float amount)` that decreases the fuel level, ensuring it never drops below zero.

## Exercise

Implement a `Weapon` class with private attributes for `name`, `damage`, and `durability`. Include a constructor to initialize these values and a method `useWeapon()` that reduces durability by 5 each time it is called and prints out the remaining durability.

## Exercise

Design a `CoffeeMaker` class that encapsulates `waterLevel` (float) and `isPoweredOn` (bool). Add a constructor, a method `togglePower()` to switch power on and off, and a method `brew()` that checks if the maker is powered on and has at least 0.5 units of water before brewing.
