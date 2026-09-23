#include <algorithm>
#include <chrono>
#include <print>
#include <vector>

class Node {
public:
  int data;
  Node* next;

  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

void insertAt(Node*& head, int value, int position) {
  if (position == 0) {
    head = new Node(value, head);
    return;
  }

  Node* current = head;

  for (int i = 0; i < position - 1 && current != nullptr; ++i) {
    current = current->next;
  }

  if (current != nullptr) {
    current->next = new Node(value, current->next);
  }
}

void swapData(Node* head, int val1, int val2) {
  Node* first = nullptr;
  Node* second = nullptr;

  Node* current = head;

  while (current != nullptr) {
    if (current->data == val1) first = current;
    if (current->data == val2) second = current;
    current = current->next;
  }

  if (first != nullptr && second != nullptr) {
    std::swap(first->data, second->data);
  }
}

void swapVectorValues(std::vector<int>& values, int val1, int val2) {
  auto first = std::find(values.begin(), values.end(), val1);
  auto second = std::find(values.begin(), values.end(), val2);

  if (first != values.end() && second != values.end()) {
    std::swap(*first, *second);
  }
}

void deleteList(Node*& head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  const int N = 1000000;
  const int SWAPS = 100;

  Node* listHead = nullptr;
  std::vector<int> vec;

  // Build the linked list by inserting at position zero
  for (int i = 0; i < N; ++i) {
    insertAt(listHead, i, 0);
  }

  // Build the vector
  for (int i = 0; i < N; ++i) {
    vec.push_back(i);
  }

  // Swap values in the linked list
  auto startListSwap = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < SWAPS; ++i) {
    int firstValue = i;
    int secondValue = N - 1 - i;
    swapData(listHead, firstValue, secondValue);
  }

  auto endListSwap = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> listSwapTime =
      endListSwap - startListSwap;

  // Swap values in the vector
  auto startVectorSwap = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < SWAPS; ++i) {
    int firstValue = i;
    int secondValue = N - 1 - i;
    swapVectorValues(vec, firstValue, secondValue);
  }

  auto endVectorSwap = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> vectorSwapTime =
      endVectorSwap - startVectorSwap;

  std::println("Linked list swap: {}s",
               listSwapTime.count());
  std::println("Vector swap: {}s",
               vectorSwapTime.count());

  deleteList(listHead);

  return 0;
}
