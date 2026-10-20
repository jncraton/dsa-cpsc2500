#include <algorithm>
#include <print>
#include <vector>

void inssort(std::vector<int> &A) {
  for (int i = 1; i < A.size(); i++) {
    for (int j = i; j > 0 && A[j] < A[j - 1]; j--) {
      std::swap(A[j], A[j - 1]);
    }
  }
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
  inssort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
