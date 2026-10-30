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
  unsigned int left_idx = first;
  unsigned int right_idx = mid + 1;
  unsigned int merged_idx = first;

  // Active merging
  while (left_idx <= mid && right_idx <= last) {
    if (A[left_idx] <= A[right_idx]) {
      tmp[merged_idx] = A[left_idx];
      left_idx++;
    } else {
      tmp[merged_idx] = A[right_idx];
      right_idx++;
    }
    merged_idx++;
  }

  // Merge remaining elements from the left side
  while (left_idx <= mid) {
    tmp[merged_idx] = A[left_idx];
    left_idx++;
    merged_idx++;
  }

  // Or merge remaining elements from the right side
  while (right_idx <= last) {
    tmp[merged_idx] = A[right_idx];
    right_idx++;
    merged_idx++;
  }

  // Copy the merged elements back into the original array
  for (unsigned int m = first; m <= last; ++m) {
    A[m] = tmp[m];
  }
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
  std::vector<int> tmp(data.size(), 0);
  mergesort(data, tmp, 0, data.size() - 1);
  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
