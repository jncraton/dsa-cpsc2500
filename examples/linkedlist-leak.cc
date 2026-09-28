#include <print>
#include <sys/resource.h>
#include <vector>

long peak_memory_kb() {
  rusage usage{};
  getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss;
}

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

void leakyRemove(Node *&head, int value) {
  if (head == nullptr)
    return;

  if (head->data == value) {
    Node *temp = head;
    head = head->next;
    return;
  }

  Node *curr = head;
  while (curr->next != nullptr && curr->next->data != value) {
    curr = curr->next;
  }

  if (curr->next != nullptr) {
    Node *temp = curr->next;
    curr->next = curr->next->next;
  }
}

int main() {
  Node *head = nullptr;

  for (int i = 0; i < 10000000; ++i) {
    head = new Node(42);
    leakyRemove(head, 42);

    if (i % 1000000 == 0) {
      std::println("{} kB memory reserved", peak_memory_kb());
    }
  }

  return 0;
}