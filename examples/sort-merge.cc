#include <algorithm>
#include <print>
#include <vector>

void mergesort(std::vector<int> &A, std::vector<int> &tmp, int first,
               int last) {

  // Base case, 1 item already "sorted"
  if (first >= last) {
    return;
  }

  // Compute midpoint and sort halves
  unsigned int mid = first + (last - first) / 2;
  mergesort(A, tmp, first, mid);
  mergesort(A, tmp, mid + 1, last);

  // Merge sorted halves
  unsigned int i = first;
  unsigned int j = mid + 1;
  unsigned int k = first;

  // Actve merging
  while (i <= mid && j <= last) {
    if (A[i] <= A[j]) {
      tmp[k] = A[i];
      i++;
    } else {
      tmp[k] = A[j];
      j++;
    }
    k++;
  }

  // Merge left side
  while (i <= mid) {
    tmp[k] = A[i];
    i++;
    k++;
  }

  // Or merge right side
  while (j <= last) {
    tmp[k] = A[j];
    j++;
    k++;
  }

  for (unsigned int m = first; m <= last; ++m) {
    A[m] = tmp[m];
  }
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
  std::vector<int> tmp = {0, 0, 0, 0, 0, 0, 0};
  mergesort(data, tmp, 0, 6);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
