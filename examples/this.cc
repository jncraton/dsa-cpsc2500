#include <print>

class Rectangle {
private:
  int width;
  int height;

public:
  Rectangle(int width, int height) {
    this->width = width;
    this->height = height;
  }

  int area() { return width * height; }
};

int main() {
  Rectangle rect = Rectangle(10, 20);

  std::println("Area: {}", rect.area());
}