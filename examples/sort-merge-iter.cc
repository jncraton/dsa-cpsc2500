#include <algorithm>
#include <print>
#include <vector>

void mergesort(std::vector<int> &A) {
  int total_size = static_cast<int>(A.size());
  if (total_size < 2) {
    return;
  }

  std::vector<int> tmp(total_size);

  for (int block_size = 1; block_size < total_size; block_size *= 2) {
    for (int block_start = 0; block_start < total_size;
         block_start += 2 * block_size) {
      int mid_point = std::min(block_start + block_size, total_size);
      int block_end = std::min(block_start + 2 * block_size, total_size);

      int left_ptr = block_start;
      int right_ptr = mid_point;
      int merged_ptr = block_start;

      // Active merge
      while (left_ptr < mid_point && right_ptr < block_end) {
        if (A[left_ptr] <= A[right_ptr]) {
          tmp[merged_ptr] = A[left_ptr];
          left_ptr++;
        } else {
          tmp[merged_ptr] = A[right_ptr];
          right_ptr++;
        }
        merged_ptr++;
      }

      // Merge remaining left
      while (left_ptr < mid_point) {
        tmp[merged_ptr] = A[left_ptr];
        left_ptr++;
        merged_ptr++;
      }

      // Merge remaining right
      while (right_ptr < block_end) {
        tmp[merged_ptr] = A[right_ptr];
        right_ptr++;
        merged_ptr++;
      }

      // Copy back
      for (int current_idx = block_start; current_idx < block_end;
           ++current_idx) {
        A[current_idx] = tmp[current_idx];
      }
    }
  }
}

int main() {
  std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};

  mergesort(data);

  for (int n : data) {
    std::println("{}", n);
  }
  return 0;
}
