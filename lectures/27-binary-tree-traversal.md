---
reading: '[Binary Tree Traversals](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BinaryTreeTraversal.html), [Writing Traversals](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/WritingTraversals.html)'
teaching_goal: Students will understand how to traverse binary trees using recursive methods.
learning_objectives:
  - Define preorder, inorder, and postorder traversals
  - Identify the correct order of operations for each traversal
  - Implement recursive traversals using a base case and recursive step
  - Recognize the "bad" pattern of checking children before recursing
  - Apply traversals to common tasks like printing or deleting nodes
---

# Binary Tree Traversals

## Definition

- Traversal: Process every node in a tree exactly once
- Enumeration: A traversal that lists nodes in a specific order
- Order matters for many applications
- Recursive nature: Each node is the root of its own subtree

## Preorder Traversal

- Visit order: Root $\rightarrow$ Left $\rightarrow$ Right
- Use case: Copying a tree (create parent before children)
- Logic:
  1. Visit current node
  2. Recurse on left subtree
  3. Recurse on right subtree

## Inorder Traversal

- Visit order: Left $\rightarrow$ Root $\rightarrow$ Right
- Use case: Binary Search Trees (prints values in sorted order)
- Logic:
  1. Recurse on left subtree
  2. Visit current node
  3. Recurse on right subtree

## Postorder Traversal

- Visit order: Left $\rightarrow$ Right $\rightarrow$ Root
- Use case: Deleting a tree (delete children before parent)
- Logic:
  1. Recurse on left subtree
  2. Recurse on right subtree
  3. Visit current node

## Recursive Implementation

```cpp
void preorder(BinNode* rt) {
  if (rt == null) return;
  visit(rt);
  preorder(rt->left);
  preorder(rt->right);
}
```

## The Base Case

- Most common base case: `rt == null`
- Return immediately
- An empty subtree requires no processing

## The Recursive Step

- Let the children take care of themselves
- Do not check if children are null before recursing
- The recursive call handles the null check as its base case

## Bad Practice: Redundant Checks

```cpp
// Avoid this pattern
void preorder2(BinNode* rt) {
  visit(rt);
  if (rt->left != null) preorder2(rt->left);
  if (rt->right != null) preorder2(rt->right);
}
```

---

- Why it is bad?
  - Fails if the initial root is null
  - Accesses child pointers twice
  - Increases complexity without performance gain

## Exercise

Write a preorder traversal that prints the value of each node.

## Exercise

Given a tree where you must delete all nodes, which traversal is required?

## Exercise

A tree has nodes A, B, C. A is root. B is left child. C is right child. List the inorder traversal.
