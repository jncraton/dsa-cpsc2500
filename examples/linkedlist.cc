#include <print>

class Node {
public:
  int data;
  Node *next;

  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

void printList(Node *head) {
  Node *current = head;
  while (current != nullptr) {
    std::print("{} -> ", current->data);
    current = current->next;
  }
  std::println("nullptr");
}

int main() {
  // Allocate nodes
  Node *first = new Node(12);
  Node *second = new Node(99);
  Node *third = new Node(37);

  // Connect nodes
  first->next = second;
  second->next = third;

  // Traverse and print
  Node *current = first;
  while (current != nullptr) {
    std::println("Node data: {}", current->data);
    current = current->next;
  }

  printList(first);

  // Clean up
  delete third;
  delete second;
  delete first;

  return 0;
}
