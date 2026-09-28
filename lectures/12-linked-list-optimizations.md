---
teaching_goal: Students will learn how to optimize the basic singly linked list by introducing a tail pointer and a doubly linked list structure, understanding how these changes affect the efficiency of common operations.
learning_objectives:
  - Explain how a tail pointer improves the efficiency of appending elements
  - Define a doubly linked list and its advantages over a singly linked list
  - Implement a doubly linked list with head and tail pointers
  - Compare the performance of push_back and removal operations across different list types
---

# Linked List Optimizations

---

Think about linked lists as we have discussed them together so far. What are some weaknesses? What could you imagine improving?

---

Discuss weaknesses of linked lists with a partner. What could you imagine improving?

## Tail Pointer

- A singly linked list only tracks the head
- Appending to the end requires traversing the entire list
- A tail pointer tracks the last node directly
- Appending becomes a constant time operation

---

## Tail Pointer Implementation

- The list structure now holds both `head` and `tail`
- `pushBack` no longer needs a `while` loop
- `tail` is updated every time a new node is added

---

```cpp
class Node {
public:
  int data;
  Node* next;
  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

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
```

## Performance


---

```cpp
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
```

## Result

- Tail pointer makes `pushBack` significantly faster
- Singly linked list requires traversal to find the end
- Tail list provides direct access to the end
S

## Doubly Linked Lists

- Each node contains two pointers: `next` and `prev`
- Allows traversal in both directions
- Simplifies deletion of a node when its pointer is known

---

![Doubly Linked List](https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg){height=80px}

## Doubly Linked Node

- `prev` points to the preceding node
- `next` points to the succeeding node
- `nullptr` indicates the start or end of the list

---

```cpp
class DNode {
public:
  int data;
  DNode* next;
  DNode* prev;

  DNode(int data, DNode* next = nullptr, DNode* prev = nullptr) 
    : data(data), next(next), prev(prev) {}
};
```

## Doubly Linked List

- Head and tail pointers are still useful
- Deleting a node is more efficient because we have the `prev` pointer
- No need to traverse from the head to find the predecessor

---

```cpp
void pushBackDoubly(DNode*& head, DNode*& tail, int value) {
  DNode* newNode = new DNode(value, nullptr, tail);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void removeValueDoubly(DNode*& head, DNode*& tail, int value) {
  DNode* current = head;
  while (current != nullptr) {
    if (current->data == value) {
      if (current->prev) current->prev->next = current->next;
      if (current->next) current->next->prev = current->prev;
      if (current == head) head = current->next;
      if (current == tail) tail = current->prev;
      delete current;
      return;
    }
    current = current->next;
  }
}
```

---

## Doubly Linked Removal

- Removing a node in a singly list requires finding the predecessor
- Removing a node in a doubly list is faster if you have the node pointer

---

```cpp
#include <print>
#include <vector>
#include <chrono>

class DNode {
public:
  int data;
  DNode* next;
  DNode* prev;
  DNode(int data, DNode* next = nullptr, DNode* prev = nullptr) 
    : data(data), next(next), prev(prev) {}
};

void pushBackDoubly(DNode*& head, DNode*& tail, int value) {
  DNode* newNode = new DNode(value, nullptr, tail);
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void removeValueDoubly(DNode*& head, DNode*& tail, int value) {
  DNode* curr = head;
  while (curr != nullptr) {
    if (curr->data == value) {
      if (curr->prev) curr->prev->next = curr->next;
      if (curr->next) curr->next->prev = curr->prev;
      if (curr == head) head = curr->next;
      if (curr == tail) tail = curr->prev;
      delete curr;
      return;
    }
    curr = curr->next;
  }
}

int main() {
  const int N = 50000;
  DNode* headD = nullptr;
  DNode* tailD = nullptr;
  for (int i = 0; i < N; ++i) pushBackDoubly(headD, tailD, i);

  auto start = std::chrono::high_resolution_clock::now();
  removeValueDoubly(headD, tailD, N / 2);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  std::println("Doubly List Removal: {}s", diff.count());

  // Cleanup
  while (headD != nullptr) {
    DNode* temp = headD;
    headD = headD->next;
    delete temp;
  }
  return 0;
}
```

## Reverse Traversal

- Suppose a program needs to process a linked list from the last item to the first
- A singly linked list does not provide a direct way to move backward

## Strategies

1. Start at the beginning for every item
2. Copy the values into a contiguous container, then traverse the copy backward
3. Use a doubly linked list and follow `prev` pointers from the tail


## Reverse Traversal Performance

```cpp
#include <chrono>
#include <print>
#include <vector>

class Node {
public:
  int data;
  Node* next;

  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class DNode {
public:
  int data;
  DNode* next;
  DNode* prev;

  DNode(int data, DNode* next = nullptr, DNode* prev = nullptr)
    : data(data), next(next), prev(prev) {}
};

void pushBack(Node*& head, Node*& tail, int value) {
  Node* newNode = new Node(value);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void pushBackDoubly(DNode*& head, DNode*& tail, int value) {
  DNode* newNode = new DNode(value, nullptr, tail);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

long long reverseNaive(Node* head, int size) {
  long long total = 0;

  for (int reverseIndex = size - 1; reverseIndex >= 0; --reverseIndex) {
    Node* current = head;

    for (int index = 0; index < reverseIndex; ++index) {
      current = current->next;
    }

    total += current->data;
  }

  return total;
}

long long reverseCopy(Node* head) {
  std::vector<int> values;

  for (Node* current = head; current != nullptr; current = current->next) {
    values.push_back(current->data);
  }

  long long total = 0;

  for (auto current = values.rbegin(); current != values.rend(); ++current) {
    total += *current;
  }

  return total;
}

long long reverseDoubly(DNode* tail) {
  long long total = 0;

  for (DNode* current = tail; current != nullptr; current = current->prev) {
    total += current->data;
  }

  return total;
}

void deleteList(Node*& head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

void deleteList(DNode*& head) {
  while (head != nullptr) {
    DNode* temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  const int N = 20000;
  const int repetitions = 5;

  Node* head = nullptr;
  Node* tail = nullptr;
  DNode* headD = nullptr;
  DNode* tailD = nullptr;

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
```

---

When might copying a singly linked list be preferable to changing it into a doubly linked list?

---

Which strategy should be chosen when reverse traversal will happen many times?

---

How does the memory overhead of a doubly linked list compare to a singly linked list?

---

What operations become faster when a list has a tail pointer?
