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

  int area() { return width * height; }
};

int main() {
  Rectangle rect;

  rect.setDimensions(10, 20);

  std::println("Area: {}", rect.area());
}