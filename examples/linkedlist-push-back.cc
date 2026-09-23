#include <chrono>
#include <print>
#include <vector>

class Node {
public:
  int data;
  Node *next;
  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

void pushBack(Node *&head, int value) {
  if (head == nullptr) {
    head = new Node(value);
    return;
  }
  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = new Node(value);
}

int main() {
  const int N = 10000;
  Node *listHead = nullptr;
  std::vector<int> vec;

  // Push Back Test
  auto startList = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i)
    pushBack(listHead, i);
  auto endList = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffList = endList - startList;
  std::println("List Push Back: {}s", diffList.count());

  auto startVec = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i)
    vec.push_back(i);
  auto endVec = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffVec = endVec - startVec;
  std::println("Vector Push Back: {}s", diffVec.count());

  // Cleanup
  while (listHead != nullptr) {
    Node *temp = listHead;
    listHead = listHead->next;
    delete temp;
  }
  return 0;
}
