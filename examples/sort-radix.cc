#include <print>
#include <vector>
#include <algorithm>
#include <cmath>

void radix_sort(std::vector<int>& A) {
  if (A.empty()) return;

  int max_val = 0;
  for (int x : A) {
    if (x > max_val) max_val = x;
  }

  int exp = 1;
  while (max_val / exp > 0) {
    std::vector<int> output(A.size());
    std::vector<int> count(10, 0);

    for (size_t i = 0; i < A.size(); ++i) {
      count[(A[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
      count[i] += count[i - 1];
    }

    for (int i = A.size() - 1; i >= 0; --i) {
      output[count[(A[i] / exp) % 10] - 1] = A[i];
      count[(A[i] / exp) % 10]--;
    }

    A = output;
    exp *= 10;
  }
}

int main() {
  std::vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};
  radix_sort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
