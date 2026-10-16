#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

void bubblesort(std::list<int>& list) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    auto it = list.begin();
    auto next = std::next(it);
    while (next != list.end()) {
      if (*it > *next) {
        std::swap(*it, *next);
        swapped = true;
      }
      it = next;
      next = std::next(next);
    }
  }
}

int main() {
  std::list<int> data = {64, 34, 25, 12, 22, 11, 90};
  bubblesort(data);
  for (int n : data) {
    std::cout << n << " ";
  }
  return 0;
}
