#include <chrono>
#include <print>
#include <vector>

class DNode {
public:
  int data;
  DNode *next;
  DNode *prev;
  DNode(int data, DNode *next = nullptr, DNode *prev = nullptr)
      : data(data), next(next), prev(prev) {}
};

void pushBackDoubly(DNode *&head, DNode *&tail, int value) {
  DNode *newNode = new DNode(value, nullptr, tail);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void removeValueDoubly(DNode *&head, DNode *&tail, int value) {
  DNode *curr = head;
  while (curr != nullptr) {
    if (curr->data == value) {
      if (curr->prev)
        curr->prev->next = curr->next;
      if (curr->next)
        curr->next->prev = curr->prev;
      if (curr == head)
        head = curr->next;
      if (curr == tail)
        tail = curr->prev;
      delete curr;
      return;
    }
    curr = curr->next;
  }
}

int main() {
  const int N = 50000;
  DNode *headD = nullptr;
  DNode *tailD = nullptr;
  for (int i = 0; i < N; ++i)
    pushBackDoubly(headD, tailD, i);

  auto start = std::chrono::high_resolution_clock::now();
  removeValueDoubly(headD, tailD, N / 2);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  std::println("Doubly List Removal: {}s", diff.count());

  // Cleanup
  while (headD != nullptr) {
    DNode *temp = headD;
    headD = headD->next;
    delete temp;
  }
  return 0;
}
