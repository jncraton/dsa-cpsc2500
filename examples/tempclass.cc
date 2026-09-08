#include <print>
#include <iostream>

class Temperature {
  double kelvin;

public:
  Temperature() : kelvin(0.0) {}

  void set_kelvin(double k) {
    kelvin = k;
  }

  double get_kelvin() const {
    return kelvin;
  }

  void set_celsius(double c) {
    kelvin = c + 273.15;
  }

  double get_celsius() const {
    return kelvin - 273.15;
  }

  void set_fahrenheit(double f) {
    kelvin = (f - 32) * 5 / 9 + 273.15;
  }

  double get_fahrenheit() const {
    return (kelvin - 273.15) * 9 / 5 + 32;
  }
};

int main() {
  Temperature t;
  t.set_celsius(25.0);
  std::println("Kelvin: {}", t.get_kelvin());
  std::println("Fahrenheit: {}", t.get_fahrenheit());
  return 0;
}
