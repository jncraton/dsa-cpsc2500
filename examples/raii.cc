#include <print>

class IntValue {
public:
  explicit IntValue(int value) : value_(new int(value)) {}

  ~IntValue() { delete value_; }

  IntValue(const IntValue &) = delete;
  IntValue &operator=(const IntValue &) = delete;

  int get() const { return *value_; }

private:
  int *value_;
};

int main() {
  IntValue value(42);
  std::println("Value: {}", value.get());
}
