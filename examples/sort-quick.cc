#include <algorithm>
#include <print>
#include <vector>

void quicksort_recursive(std::vector<int> &A, int first, int last) {
  // Base case: 0 or 1 item already "sorted"
  if (first >= last) {
    return;
  }

  // Choose a pivot (middle element)
  int pivot = A[first + (last - first) / 2];
  
  // Partitioning logic
  int i = first;
  int j = last;

  while (i <= j) {
    while (A[i] < pivot) {
      i++;
    }
    while (A[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(A[i], A[j]);
      i++;
      j--;
    }
  }

  // Recursive calls on the partitioned halves
  quicksort_recursive(A, first, j);
  quicksort_recursive(A, i, last);
}

void quicksort(std::vector<int> &A) {
  if (A.empty()) {
    return;
  }

  quicksort_recursive(A, 0, static_cast<int>(A.size()) - 1);
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};

  quicksort(data);

  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}