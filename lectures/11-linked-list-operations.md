---
teaching_goal: Students will learn to perform common operations on singly linked lists, including insertion at the end, middle, and removal, while observing the performance trade-offs of these operations compared to dynamic arrays.
learning_objectives:
  - Implement push_back to add elements to the end of a list
  - Implement insert to add elements at a specific position
  - Implement remove to delete nodes from the list
  - Implement swap to exchange data between two nodes
  - Compare the performance of these operations against std::vector
---

# Linked List Operations

## Push Back

- Adding to the end of a list
- Requires traversing from the head to the last node
- No tail pointer means we must visit every node

---

```cpp
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
```

## Insert at Position

- Adding an element at a specific index
- Requires traversing to the node just before the target position
- Must update pointers to maintain list integrity

---

```cpp
void insertAt(Node*& head, int value, int position) {
  if (position == 0) {
    head = new Node(value, head);
    return;
  }

  Node* current = head;
  for (int i = 0; i < position - 1 && current != nullptr; ++i) {
    current = current->next;
  }

  if (current != nullptr) {
    current->next = new Node(value, current->next);
  }
}
```

## Remove Node

- Deleting a node by value
- Requires finding the node before the one to be deleted
- Must free the memory of the removed node

---

```cpp
void removeValue(Node*& head, int value) {
  if (head == nullptr) return;

  if (head->data == value) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node* current = head;
  while (current->next != nullptr && current->next->data != value) {
    current = current->next;
  }

  if (current->next != nullptr) {
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
  }
}
```

## Swap Data

- Exchanging data between two nodes
- Does not change the structure of the list
- Only swaps the `data` members

---

```cpp
void swapData(Node* head, int val1, int val2) {
  Node* first = nullptr;
  Node* second = nullptr;

  Node* current = head;
  while (current != nullptr) {
    if (current->data == val1) first = current;
    if (current->data == val2) second = current;
    current = current->next;
  }

  if (first && second) {
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
  }
}
```

## Performance Comparison

- We compare these operations against `std::vector`
- We measure the time taken for large lists

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

int main() {
  const int N = 10000;
  Node* listHead = nullptr;
  std::vector<int> vec;

  // Push Back Test
  auto startList = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) pushBack(listHead, i);
  auto endList = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffList = endList - startList;
  std::println("List Push Back: {}s", diffList.count());

  auto startVec = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) vec.push_back(i);
  auto endVec = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diffVec = endVec - startVec;
  std::println("Vector Push Back: {}s", diffVec.count());

  // Cleanup
  while (listHead != nullptr) {
    Node* temp = listHead;
    listHead = listHead->next;
    delete temp;
  }
  return 0;
}
```

## Results

- `push_back` on a list without a tail pointer is slow
- `vector::push_back` is much faster due to amortized constant time
- `insert` and `remove` in the middle are similar in behavior
- `swap` is efficient as it avoids pointer manipulation

---

How does the lack of a tail pointer affect the efficiency of adding elements to the end of a list?

## Exercise

Implement a function `countNodes(Node* head)` that returns the number of nodes in a list. Verify the size of your list after several `pushBack` and `removeValue` operations. How does time required to count nodes change with list size?
