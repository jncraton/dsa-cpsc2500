#include <print>
#include <vector>
#include <algorithm>

void binsort(std::vector<int>& A) {
  int max_val = 0;
  for (int x : A) {
    if (x > max_val) max_val = x;
  }

  std::vector<std::vector<int>> bins(max_val + 1);
  for (int x : A) {
    bins[x].push_back(x);
  }

  int idx = 0;
  for (int i = 0; i <= max_val; ++i) {
    for (int x : bins[i]) {
      A[idx++] = x;
    }
  }
}

int main() {
  std::vector<int> data = {5, 2, 9, 1, 5, 6};
  binsort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
