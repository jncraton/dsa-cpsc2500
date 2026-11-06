---
reading: '[Graph Traversals](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/GraphTraversal.html)'
teaching_goal: Students will understand the fundamental graph traversal algorithms
learning_objectives:
  - Describe the difference between DFS and BFS
  - Explain the use of stacks and queues in traversals
  - Identify the time complexity of both algorithms
  - Implement basic DFS and BFS logic
---

# Graph Traversals

## Overview

- Visit vertices in specific order
- Similar to tree traversals
- Useful for pathfinding and connectivity
- Handles cycles and disconnected components

## Handling Cycles

- Use a VISITED flag
- Initialize all vertices as UNVISITED
- Mark vertex as VISITED upon first encounter
- Prevents infinite loops in cyclic graphs

## Complete Traversal

- Start from an arbitrary vertex
- If some vertices remain UNVISITED
- Pick an unvisited vertex and restart
- Ensures all components are visited

## Depth-First Search

- Follows one branch to its conclusion
- Uses a stack (implicitly via recursion)
- Explores "deep" before "wide"
- Good for finding paths or cycles

## DFS Logic

- PreVisit: action before exploring neighbors
- Mark current vertex VISITED
- Recursively visit unvisited neighbors
- PostVisit: action after exploring neighbors

## DFS Implementation

```cpp
static void DFS(Graph G, int v) {
    PreVisit(G, v);
    G.setValue(v, VISITED);
    int[] nList = G.neighbors(v);
    for (int i = 0; i < nList.length; i++) {
      if (G.getValue(nList[i]) != VISITED) {
        DFS(G, nList[i]);
      }
    }
    PostVisit(G, v);
}
```

---

How does DFS behave on a graph with a cycle?

## Breadth-First Search

- Explores all neighbors first
- Uses a queue (FIFO)
- Explores "wide" before "deep"
- Good for finding shortest paths in unweighted graphs

## BFS Logic

- Enqueue start vertex
- Mark start vertex VISITED
- While queue is not empty:
  1. Dequeue vertex v
  2. PreVisit(v)
  3. For each neighbor u of v:
     - If u is UNVISITED:
       - Mark u VISITED
       - Enqueue u
  4. PostVisit(v)

## BFS Implementation

```cpp
static void BFS(Graph G, int v) {
    LQueue Q = new LQueue(G.nodeCount());
    Q.enqueue(v);
    G.setValue(v, VISITED);
    while (Q.length() > 0) {
      v = (Integer) Q.dequeue();
      PreVisit(G, v);
      int[] nList = G.neighbors(v);
      for (int i = 0; i < nList.length; i++) {
        if (G.getValue(nList[i]) != VISITED) {
          G.setValue(nList[i], VISITED);
          Q.enqueue(nList[i]);
        }
      }
      PostVisit(G, v);
    }
}
```

---

Which algorithm is better for finding the shortest path?

## Complexity Analysis

- Time Complexity: $O(|V| + |E|)$
- Each vertex visited once
- Each edge explored once
- Space Complexity: $O(|V|)$
- Depends on stack/queue size

## Comparison

| Feature | DFS | BFS |
| --- | --- | --- |
| Data Structure | Stack (Recursion) | Queue |
| Strategy | Depth-first | Breadth-first |
| Best Use Case | Pathfinding/Cycles | Shortest Path |
| Memory | $O(\text{depth})$ | $O(\text{width})$ |

## Exercise

Implement a program that uses BFS to find the shortest path between two nodes in a small graph.
