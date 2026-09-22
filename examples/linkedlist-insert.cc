#include <print>
#include <vector>
#include <chrono>

class Node {
public:
  int data;
  Node* next;
  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

void insertAtHead(Node*& head, int value) {
  Node* newNode = new Node(value, head);
  head = newNode;
}

int main() {
  // Linked List Test
  Node* listHead = nullptr;
  auto startList = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100000; ++i) {
    insertAtHead(listHead, i);
  }
  auto endList = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffList = endList - startList;
  std::println("List Head Insertion: {}s", diffList.count());

  // Vector Test
  std::vector<int> vec;
  auto startVec = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100000; ++i) {
    vec.insert(vec.begin(), i);
  }
  auto endVec = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffVec = endVec - startVec;
  std::println("Vector Head Insertion: {}s", diffVec.count());

  // Cleanup
  while (listHead != nullptr) {
    Node* temp = listHead;
    listHead = listHead->next;
    delete temp;
  }
  return 0;
}
