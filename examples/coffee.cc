#include <print>

class CoffeeMaker {
private:
  float waterLevel;
  bool isPoweredOn;

public:
  CoffeeMaker() {
    waterLevel = 1.0;
    isPoweredOn = false;
  }

  void togglePower() { isPoweredOn = !isPoweredOn; }

  void brew() {
    if (isPoweredOn && waterLevel >= 0.5) {
      waterLevel -= 0.5;
      std::println("Brewing...");
    } else {
      std::println("Unable to brew. :(");
    }
  }
};

int main() {
  CoffeeMaker pot;

  pot.togglePower();
  pot.brew();
  pot.brew();
  pot.brew();

  return 0;
}