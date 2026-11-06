---
reading: '[General Trees](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/GenTreeIntro.html), [Union/Find](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/UnionFind.html), [Sequential Rep](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/SequentialRep.html)'
teaching_goal: Students will understand general tree structures, Union/Find operations, and sequential representations.
learning_objectives:
  - Define general trees and their terminology
  - Implement a general tree ADT using first-child/next-sibling
  - Explain Union/Find using parent pointers
  - Describe path compression and weighted union
  - Compare sequential tree representations for space and time
---

# General Trees

## Definition

- Finite set of nodes
- One designated root
- Nodes partitioned into disjoint subtrees
- Subtrees ordered left to right

## Terminology

- Out-degree: number of children
- Forest: collection of trees
- Parent: node above a child
- Sibling: nodes sharing a parent
- Ancestor: any node on path to root

## General Tree ADT

- Arbitrary number of children
- Binary trees are restricted cases
- Need flexible access to children

## Implementation Strategy

- First-child / Next-sibling
- `leftmostChild()`
- `rightSibling()`
- Children traversed like a list

---

## Preorder Traversal

- Visit root first
- Visit subtrees left to right
- Recursive approach

## Preorder Code

```cpp
static void preorder(GTNode rt) {
  PrintNode(rt);
  if (!rt.isLeaf()) {
    GTNode temp = rt.leftmostChild();
    while (temp != null) {
      preorder(temp);
      temp = temp.rightSibling();
    }
  }
}
```

---

## Union/Find Problem

- Disjoint sets: no shared members
- FIND: determine if in same set
- UNION: merge two sets

## Parent Pointer Tree

- Store only parent pointer
- Each node points to parent
- Root has no parent (e.g., -1)
- Space efficient for Union/Find

## FIND Operation

- Follow parent pointers to root
- If roots match, nodes are in same set

## UNION Operation

- Find roots of both nodes
- If different, point one root to other

## Weighted Union

- Join smaller tree to larger tree
- Keeps tree height small
- Depth increases at most $O(\log n)$

## Path Compression

- Flatten tree during FIND
- Point all nodes on path to root
- Near-constant amortized time

## Complexity

- $O(n \log^* n)$ for $n$ operations
- $\log^* n$ grows extremely slowly

## Sequential Representation

- Store nodes in a list
- No pointers used
- Space efficient for archiving/disk
- Time inefficient for random access

## Binary Sequential

- Preorder traversal list
- NULLs indicate leaves
- Overhead fraction 1/2

## General Sequential

- Preorder traversal list
- Include child count or end marks
- Example: `)` marks end of child list

## Comparison

| Feature | Parent Pointer | Sequential |
| --- | --- | --- |
| Primary Use | Union/Find | Archiving/Serialization |
| Space | $O(n)$ | $O(n)$ (minimal) |
| Access Time | $O(\text{height})$ | $O(n)$ |
| Flexibility | High | Low |

## Exercise

Design a system to represent a corporate hierarchy. Which representation is best for a mobile app with frequent lookups?
