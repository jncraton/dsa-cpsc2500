---
reading: '[Binary Trees](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BinaryTree.html), [Recursive Data Structure](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/RecursiveDS.html), [Theorem](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/BinaryTreeFullThm.html)'
teaching_goal: Students will understand the structure, recursive nature, and fundamental theorems of binary trees.
learning_objectives:
  - Define binary trees, nodes, paths, and depth
  - Distinguish between full and complete binary trees
  - Recognize binary trees as recursive data structures
  - Apply the Full Binary Tree Theorem to calculate leaf counts
  - Calculate the number of empty subtrees in a binary tree
---

# Binary Trees

## Definition

- A binary tree is a finite set of nodes
- It is either empty or a root node
- The root has two disjoint subtrees: left and right
- Roots of subtrees are children of the root
- Edges connect parents to children

---

![Binary Tree](https://upload.wikimedia.org/wikipedia/commons/5/5e/Binary_tree_v2.svg){height=540px}

## Terminology

- Path: Sequence of nodes where each is a parent of the next
- Ancestor: A node on the path from the root to a descendant
- Depth: Length of path from root to a node
- Height: Depth of the deepest node
- Leaf: Node with two empty children
- Internal: Node with at least one non-empty child

## Visualizing Structure

- Root is at level 0
- Depth of root is 0
- Height is the maximum depth
- Paths define the hierarchy of the data

## Full vs Complete

- Full: Every node has 0 or 2 children
- Complete: Filled level by level, left to right
- Full trees are not always complete
- Complete trees are not always full
- Memory aid: "Complete" is wider than "full"

---

![Full Binary Tree](https://upload.wikimedia.org/wikipedia/commons/b/b0/Full_binary.svg){height=540px}

---

![Complete Binary Tree](https://upload.wikimedia.org/wikipedia/commons/d/d9/Complete_binary2.svg){height=540px}

## Recursive Nature

- Recursive data structure: composed of smaller instances of itself
- List: Empty or (Node + List)
- Binary Tree: Empty or (Node + Left Tree + Right Tree)
- Recursive definitions provide models for recursive algorithms

## Full Binary Tree Theorem

- Theorem: Leaves = Internal Nodes + 1
- Applies to non-empty full binary trees
- Useful for calculating space requirements
- Example: 3 internal nodes $\implies$ 4 leaves

## Proof by Induction

- Base Case: 0 internal nodes $\implies$ 1 leaf
- Base Case: 1 internal node $\implies$ 2 leaves
- Hypothesis: $n-1$ internal nodes $\implies$ $n$ leaves
- Step: Remove a node with 2 leaf children
- Restore: Add 2 children, node becomes internal

## Empty Subtrees

- Theorem: Empty Subtrees = Nodes + 1
- Proof 1: Replace empty subtrees with leaves
- Proof 2: Total children ($2n$) minus non-empty children ($n-1$)
- Result: $2n - (n-1) = n+1$

## Exercise

Given a full binary tree with 10 internal nodes, how many leaves does it have?

## Exercise

A binary tree has 15 nodes. How many empty subtrees does it contain?
