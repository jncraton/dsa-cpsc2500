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
  const int N = 100000;

  // Linked List Test
  Node* listHead = nullptr;
  for (int i = 0; i < N; ++i) insertAtHead(listHead, i); // Helper needed or inline

  auto startList = std::chrono::high_resolution_clock::now();
  long long sumList = 0;
  for (int i = 0; i < N; ++i) {
    Node* curr = listHead;
    for (int j = 0; j < i; ++j) curr = curr->next;
    sumList += curr->data;
  }
  auto endList = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffList = endList - startList;
  std::println("List Access Sum: {}\nTime: {}s", sumList, diffList.count());

  // Vector Test
  std::vector<int> vec(N);
  for (int i = 0; i < N; ++i) vec[i] = i;

  auto startVec = std::chrono::high_resolution_clock::now();
  long long sumVec = 0;
  for (int i = 0; i < N; ++i) {
    sumVec += vec[i];
  }
  auto endVec = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffVec = endVec - startVec;
  std::println("Vector Access Sum: {}\nTime: {}s", sumVec, diffVec.count());

  return 0;
}
