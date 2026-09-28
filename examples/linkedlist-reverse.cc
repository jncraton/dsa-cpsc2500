#include <chrono>
#include <print>
#include <vector>

class Node {
public:
  int data;
  Node *next;

  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

class DNode {
public:
  int data;
  DNode *next;
  DNode *prev;

  DNode(int data, DNode *next = nullptr, DNode *prev = nullptr)
      : data(data), next(next), prev(prev) {}
};

void pushBack(Node *&head, Node *&tail, int value) {
  Node *newNode = new Node(value);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

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

long long reverseNaive(Node *head, int size) {
  long long total = 0;

  for (int reverseIndex = size - 1; reverseIndex >= 0; --reverseIndex) {
    Node *current = head;

    for (int index = 0; index < reverseIndex; ++index) {
      current = current->next;
    }

    total += current->data;
  }

  return total;
}

long long reverseCopy(Node *head) {
  std::vector<int> values;

  for (Node *current = head; current != nullptr; current = current->next) {
    values.push_back(current->data);
  }

  long long total = 0;

  for (auto current = values.rbegin(); current != values.rend(); ++current) {
    total += *current;
  }

  return total;
}

long long reverseDoubly(DNode *tail) {
  long long total = 0;

  for (DNode *current = tail; current != nullptr; current = current->prev) {
    total += current->data;
  }

  return total;
}

void deleteList(Node *&head) {
  while (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

void deleteList(DNode *&head) {
  while (head != nullptr) {
    DNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  const int N = 20000;
  const int repetitions = 5;

  Node *head = nullptr;
  Node *tail = nullptr;
  DNode *headD = nullptr;
  DNode *tailD = nullptr;

  for (int i = 0; i < N; ++i) {
    pushBack(head, tail, i);
    pushBackDoubly(headD, tailD, i);
  }

  long long naiveTotal = 0;
  long long copyTotal = 0;
  long long doublyTotal = 0;

  auto startNaive = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < repetitions; ++i) {
    naiveTotal += reverseNaive(head, N);
  }

  auto endNaive = std::chrono::high_resolution_clock::now();

  auto startCopy = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < repetitions; ++i) {
    copyTotal += reverseCopy(head);
  }

  auto endCopy = std::chrono::high_resolution_clock::now();

  auto startDoubly = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < repetitions; ++i) {
    doublyTotal += reverseDoubly(tailD);
  }

  auto endDoubly = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> naiveTime = endNaive - startNaive;
  std::chrono::duration<double> copyTime = endCopy - startCopy;
  std::chrono::duration<double> doublyTime = endDoubly - startDoubly;

  std::println("Naive reverse traversal: {}s", naiveTime.count());
  std::println("Copy then reverse: {}s", copyTime.count());
  std::println("Doubly linked reverse traversal: {}s", doublyTime.count());

  std::println("Naive checksum: {}", naiveTotal);
  std::println("Copy checksum: {}", copyTotal);
  std::println("Doubly checksum: {}", doublyTotal);

  deleteList(head);
  deleteList(headD);

  return 0;
}
