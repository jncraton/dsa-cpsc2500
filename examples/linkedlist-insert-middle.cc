#include <chrono>
#include <print>
#include <vector>

class Node {
public:
  int data;
  Node *next;

  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

void insertAt(Node *&head, int value, int position) {
  if (position <= 0 || head == nullptr) {
    head = new Node(value, head);
    return;
  }

  Node *current = head;

  for (int i = 0; i < position - 1 && current->next != nullptr; ++i) {
    current = current->next;
  }

  current->next = new Node(value, current->next);
}

void deleteList(Node *&head) {
  while (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  const int N = 1000000;
  const int inserts = 1000;
  const int position = N / 2;

  Node *listHead = nullptr;
  std::vector<int> vec;

  for (int i = 0; i < N; ++i) {
    insertAt(listHead, i, 0);
    vec.push_back(i);
  }

  auto startList = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < inserts; i++) {
    insertAt(listHead, -1, position);
  }
  auto endList = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diffList = endList - startList;
  std::println("List Insert at Position {}: {}s", position, diffList.count());

  auto startVec = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < inserts; i++) {
    vec.insert(vec.begin() + position, -1);
  }
  auto endVec = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diffVec = endVec - startVec;
  std::println("Vector Insert at Position {}: {}s", position, diffVec.count());

  deleteList(listHead);

  return 0;
}
