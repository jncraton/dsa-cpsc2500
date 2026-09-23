#include <algorithm>
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
  if (position == 0) {
    head = new Node(value, head);
    return;
  }

  Node *current = head;

  for (int i = 0; i < position - 1 && current != nullptr; ++i) {
    current = current->next;
  }

  if (current != nullptr) {
    current->next = new Node(value, current->next);
  }
}

void removeValue(Node *&head, int value) {
  if (head == nullptr) {
    return;
  }

  if (head->data == value) {
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node *current = head;

  while (current->next != nullptr && current->next->data != value) {
    current = current->next;
  }

  if (current->next != nullptr) {
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
  }
}

void removeVectorValue(std::vector<int> &values, int value) {
  auto position = std::find(values.begin(), values.end(), value);

  if (position != values.end()) {
    values.erase(position);
  }
}

void deleteList(Node *&head) {
  while (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  const int N = 100000;
  const int REMOVES = 1000;

  Node *listHead = nullptr;
  std::vector<int> vec;

  for (int i = 0; i < N; ++i) {
    insertAt(listHead, i, 0);
    vec.insert(vec.begin(), i);
  }

  std::vector<int> removedValues;

  for (int i = 0; i < REMOVES; ++i) {
    removedValues.push_back(i);
  }

  auto startList = std::chrono::high_resolution_clock::now();

  for (int value : removedValues) {
    removeValue(listHead, value);
  }

  auto endList = std::chrono::high_resolution_clock::now();

  auto startVec = std::chrono::high_resolution_clock::now();

  for (int value : removedValues) {
    removeVectorValue(vec, value);
  }

  auto endVec = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diffList = endList - startList;
  std::chrono::duration<double> diffVec = endVec - startVec;

  std::println("List Remove: {}s", diffList.count());
  std::println("Vector Remove: {}s", diffVec.count());
  std::println("List size after removals: {}", N - REMOVES);
  std::println("Vector size after removals: {}", vec.size());

  deleteList(listHead);

  return 0;
}
