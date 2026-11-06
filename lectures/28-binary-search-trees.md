---
reading: '[Binary Search Trees](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BST.html), [Dictionary Implementation Using a BST](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BSTDict.html)'
teaching_goal: Students will understand the properties, operations, and analysis of Binary Search Trees.
learning_objectives:
  - Define the binary search tree property
  - Explain the relationship between BSTs and sorted order
  - Describe the mechanics of BST insertion and search
  - Explain the logic for BST removal (including the two-child case)
  - Analyze the time complexity of BST operations in average and worst cases
  - Understand how a BST can implement a Dictionary ADT
---

# Binary Search Trees

## Definition

- A binary search tree (BST) is a binary tree
- It follows a specific ordering property
- Left subtree: all keys $\le$ root key
- Right subtree: all keys $>$ root key
- Inorder traversal of a BST yields sorted order

## BST Property

- Maintains a sorted structure
- Allows for efficient searching
- Left child is smaller
- Right child is larger
- Duplicate keys: typically inserted into the left subtree

## Search Operation

- Start at the root
- Compare target key with current node
- If target < current, go left
- If target > current, go right
- If target == current, found
- If null reached, key not present

## Search Complexity

- Average case: $O(\log n)$
- Worst case: $O(n)$
- Worst case occurs when tree is a chain (e.g., sorted input)
- Balanced trees are the goal

## Insertion

- Similar to search
- Traverse until a null position is found
- Place new node at that position
- Maintains the BST property automatically

## Insertion Complexity

- Average case: $O(\log n)$
- Worst case: $O(n)$
- Total cost for $n$ random insertions: $O(n \log n)$

## Removal Operation

- Case 1: Node is a leaf
  - Simply remove it
- Case 2: Node has one child
  - Replace node with its child
- Case 3: Node has two children
  - Find successor (smallest in right subtree)
  - Replace node's value with successor's value
  - Remove successor node

## Successor Logic

- `getmax` of left subtree OR `getmin` of right subtree
- If duplicates are in left, use max of left
- If duplicates are in right, use min of right

## Removal Complexity

- Cost depends on depth of node
- Two-child case requires finding successor
- Average case: $O(\log n)$
- Worst case: $O(n)$

## Analysis Summary

| Operation | Average | Worst |
| --- | --- | --- |
| Search | $O(\log n)$ | $O(n)$ |
| Insert | $O(\log n)$ | $O(n)$ |
| Remove | $O(\log n)$ | $O(n)$ |
| Traversal | $O(n)$ | $O(n)$ |

## Dictionary Implementation

- BST can store Key-Value Pairs (KVPairs)
- Key determines position in tree
- Value is stored at the node
- `insert(key, value)`: creates KVPair, inserts into BST
- `find(key)`: finds KVPair, returns value
- `remove(key)`: removes KVPair, returns value

## Dictionary Advantages

- Faster than unsorted list ($O(\log n)$ vs $O(n)$ search)
- Faster than sorted array ($O(\log n)$ vs $O(n)$ insert)
- Efficient balance of search and insertion

## Balancing

- Unbalanced trees lead to $O(n)$ performance
- Balanced trees guarantee $O(\log n)$
- AVL trees and Splay trees maintain balance
- 2-3 Trees are another balanced alternative

## Exercise

A BST is built by inserting: 50, 30, 70, 20, 40, 60, 80

Draw the resulting tree

## Exercise

What is the time complexity to insert 100 elements into a BST if they are inserted in strictly increasing order?
