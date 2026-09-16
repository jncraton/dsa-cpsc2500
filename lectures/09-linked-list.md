---
teaching_goal: Students will understand the limitations of arrays (fixed size, costly insertion/deletion) and learn how singly linked lists use self-referential classes with constructors and dynamic memory allocation to provide flexible data storage.
learning_objectives:
  - Identify limitations of static and dynamic arrays (contiguous memory, shifting overhead, reallocation cost)
  - Define a self-referential class (`Node`) containing public members for data and the next node
  - Implement basic linked list operations using constructors and direct member access for node creation, traversal, and insertion at the head
  - Understand the trade-offs between arrays (O(1) random access) and linked lists (O(1) head insertion, O(n) traversal)
reading: '[Linked Lists](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/ListLinked.html)'
---

# Linked Lists

## Limitations of Arrays

- Arrays require contiguous blocks of memory
- Static arrays cannot grow or shrink; dynamic arrays require costly reallocation and copying
- Inserting or deleting an element in the middle of an array requires shifting all subsequent elements

---

## Linked List

- A sequence of nodes
- Nodes do not need to be stored contiguously in memory
- Each node holds:
  1. The data value being stored
  2. The memory address of the next node in the sequence

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

|                     | Array | Linked List |
|---------------------|-------|-------------|
| Size | Fixed | Grows node by node |
| Access Time | Constant | Grows with length |
| Insertion | Shift contents | Create one node |
| Overhead | Low (only data storage) | High (extra pointer per node) |

## Exercise

Implement a simple singly linked list of `char` nodes using a `Node` class with public members for `data` and `next` that spells the word `"C++"`. Write a function to traverse and print the list using direct member access (`node->data`, `node->next`), and ensure all dynamically allocated memory is properly freed using `delete`.
