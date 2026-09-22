---
teaching_goal: Students will understand the limitations of arrays (fixed size, costly insertion/deletion) and learn how singly linked lists use self-referential classes with constructors and dynamic memory allocation to provide flexible data storage.
learning_objectives:
  - Identify limitations of static and dynamic arrays (contiguous memory, shifting overhead, reallocation cost)
  - Define a self-referential class (`Node`) containing public members for data and the next node
  - Implement basic linked list operations using constructors and direct member access for node creation, traversal, and insertion at the head
  - Compare the performance of linked list operations (insertion at head, element access) against vector operations using wall-clock time
reading: '[Linked Lists](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/ListLinked.html)'
---

# Linked Lists

## Limitations of Arrays

- Arrays require contiguous blocks of memory
- Static arrays cannot grow or shrink
- Dynamic arrays require reallocation and copying

---

## Linked List

- A sequence of nodes
- Nodes need not be stored contiguously in memory
- Each node holds:
  1. A data value
  2. The memory address of the next node

---

![Linked List](https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg){height=96px}

## Node Class

- Encapsulates data and a pointer to the next node

---

```cpp
class Node {
public:
  int data;
  Node* next;

  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};
```

## Creating and Connecting Nodes

- Nodes are allocated dynamically on the heap using `new`
- The last node in the list points to `nullptr` to indicate the end of the list

---

```cpp
#include <print>

class Node {
public:
  int data;
  Node* next;

  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

int main() {
  // Allocate nodes
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  // Connect nodes
  first->next = second;
  second->next = third;

  // Traverse and print
  Node* current = first;
  while (current != nullptr) {
    std::println("Node data: {}", current->data);
    current = current->next;
  }

  // Clean up
  delete third;
  delete second;
  delete first;

  return 0;
}
```

## Traversing a Linked List

- We cannot use integer indices like `arr[i]` because elements are not contiguous
- Instead, we start at a **head** pointer and follow `next` pointers until we reach `nullptr`

---

```cpp
void printList(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    std::print("{} -> ", current->data);
    current = current->next;
  }
  std::println("nullptr");
}
```

## Inserting at the Head

- Inserting an element at the beginning of a linked list is extremely efficient
- No shifting of existing elements is required

---

```cpp
#include <print>

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
  Node* head = nullptr;

  insertAtHead(head, 30);
  insertAtHead(head, 20);
  insertAtHead(head, 10);

  Node* current = head;
  while (current != nullptr) {
    std::print("{} -> ", current->data);
    current = current->next;
  }
  std::println("nullptr");

  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}
```

---

## Performance Comparison

- We can compare linked lists to `std::vector` by measuring execution time
- Use `std::chrono` to capture the "cost" of operations

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
```

## Result

- Linked list head insertion is much faster
- Vector head insertion requires shifting all existing elements

## Element Access

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

int main() {
  const int N = 100000;

  // Linked List Test
  Node* listHead = nullptr;
  for (int i = 0; i < N; ++i) insertAtHead(listHead, i); // Helper needed or inline

  auto startList = std::chrono::high_resolution_clock::now();
  int sumList = 0;
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
```

## Result

- Vector access is nearly instantaneous
- Linked list access time grows quadratically with the number of elements

---

|                     | Array | Linked List |
|---------------------|-------|-------------|
| Size | Fixed | Grows node by node |
| Access Time | Constant | Grows with length |
| Insertion | Shift contents | Create one node |
| Overhead | Low (only data storage) | High (extra pointer per node) |

---

When might we prefer linked lists over static or dynamic arrays?
