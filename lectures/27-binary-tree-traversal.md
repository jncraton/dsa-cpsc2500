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

## Definitions

- Traversal: Process every node in a tree exactly once
- Enumeration: A traversal that lists nodes in a specific order

## Preorder Traversal

- Visit order: Root $\rightarrow$ Left $\rightarrow$ Right
- Use case: Copying a tree (create parent before children)
- Logic:
  1. Visit current node
  2. Recurse on left subtree
  3. Recurse on right subtree

---

![Preorder](https://upload.wikimedia.org/wikipedia/commons/a/ac/Preorder-traversal.gif){height=540px}

## Inorder Traversal

- Visit order: Left $\rightarrow$ Root $\rightarrow$ Right
- Logic:
  1. Recurse on left subtree
  2. Visit current node
  3. Recurse on right subtree

---

![Inorder](https://upload.wikimedia.org/wikipedia/commons/4/48/Inorder-traversal.gif){height=540px}

## Postorder Traversal

- Visit order: Left $\rightarrow$ Right $\rightarrow$ Root
- Use case: Deleting a tree (delete children before parent)
- Logic:
  1. Recurse on left subtree
  2. Recurse on right subtree
  3. Visit current node

---

![Postorder](https://upload.wikimedia.org/wikipedia/commons/2/28/Postorder-traversal.gif){height=540px}

## Recursive Implementation

```cpp
void preorder(BinNode* rt) {
  if (rt == null) return;
  visit(rt);
  preorder(rt->left);
  preorder(rt->right);
}
```

## Base Case

- `rt == null`
- An empty subtree requires no processing

## Recursive Step

- Let the children take care of themselves
- Do not check if children are null before recursing
- The recursive call handles the null check as its base case

## Avoid Redundant Checks

```cpp
// Avoid this pattern
void preorder(BinNode* rt) {
  visit(rt);
  if (rt->left != null) preorder2(rt->left);
  if (rt->right != null) preorder2(rt->right);
}
```

## Problems

- Fails if the initial root is null
- Accesses child pointers twice
- Increases complexity without performance gain
