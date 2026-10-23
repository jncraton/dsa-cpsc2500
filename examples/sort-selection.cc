#include <algorithm>
#include <print>
#include <vector>

void selsort(std::vector<int> &A) {
  for (int i = 0; i < A.size() - 1; i++) {
    int bigindex = 0;
    for (int j = 1; j < A.size() - i; j++) {
      if (A[j] > A[bigindex]) {
        bigindex = j;
      }
    }
    std::swap(A[bigindex], A[A.size() - i - 1]);
  }
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
  selsort(data);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
