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
