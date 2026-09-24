#include <print>
#include <vector>
#include <chrono>

class Node {
public:
  int data;
  Node* next;
  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

void pushBack(Node*& head, int value) {
  if (head == nullptr) {
    head = new Node(value);
    return;
  }
  Node* current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = new Node(value);
}

void pushBackTail(Node*& head, Node*& tail, int value) {
  Node* newNode = new Node(value);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

int main() {
  const int N = 50000;
  Node* head = nullptr;
  Node* headT = nullptr;
  Node* tailT = nullptr;

  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) pushBack(head, i);
  auto end = std::chrono::high_resolution_clock::now();
  
  auto startT = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) pushBackTail(headT, tailT, i);
  auto endT = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  std::chrono::duration<double> diffT = endT - startT;

  std::println("List Push Back: {}s", diff.count());
  std::println("Tail List Push Back: {}s", diffT.count());

  // Cleanup
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  while (headT != nullptr) {
    Node* temp = headT;
    headT = headT->next;
    delete temp;
  }
  return 0;
}
