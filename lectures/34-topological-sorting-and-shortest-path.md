---
reading: '[Topological Sort](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/GraphTopsort.html), [Shortest-Paths Problems](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/GraphShortest.html)'
teaching_goal: Students will understand topological sorting and Dijkstra's algorithm for shortest paths.
learning_objectives:
  - Describe topological sort for DAGs
  - Implement topological sort using DFS and BFS
  - Explain Dijkstra's algorithm for weighted graphs
  - Compare complexity of different Dijkstra implementations
---

# Topological Sort

## Problem Definition

- Schedule tasks with prerequisites
- Model as a Directed Acyclic Graph (DAG)
- Directed: Prerequisite relationship
- Acyclic: No circular dependencies
- Goal: Linear order satisfying all rules

## Topological Sort

- Linear ordering of vertices
- Each edge $(u, v)$ means $u$ comes before $v$
- Only possible in DAGs
- Multiple valid sorts may exist

## DFS Solution

- Use Depth-First Search
- Visit vertex, recurse on neighbors
- Print vertex after visiting all neighbors
- Result is reverse topological order
- Reverse the final list to get the sort

## DFS Implementation

```cpp
void tophelp(Graph G, int v) {
  G.setValue(v, VISITED);
  int[] nList = G.neighbors(v);
  for (int i = 0; i < nList.length; i++) {
    if (G.getValue(nList[i]) != VISITED) {
      tophelp(G, nList[i]);
    }
  }
  printout(v);
}
```

---

## Queue-based Solution

- Also known as Kahn's Algorithm
- Count incoming edges (in-degree) for each vertex
- Queue vertices with in-degree 0
- While queue not empty:
  1. Dequeue $v$ and print
  2. For each neighbor $w$ of $v$:
     - Decrement in-degree of $w$
     - If in-degree of $w$ is 0, enqueue $w$
- If queue empty but nodes remain, cycle exists

## Queue Implementation

```cpp
void topsortBFS(Graph G) {
  Queue Q = new LQueue(G.nodeCount());
  int[] Count = new int[G.nodeCount()];
  // ... initialize Count with in-degrees ...
  for (int v = 0; v < G.nodeCount(); v++) {
    if (Count[v] == 0) Q.enqueue(v);
  }
  while (Q.length() > 0) {
    v = (Integer)Q.dequeue();
    printout(v);
    int[] nList = G.neighbors(v);
    for (int i = 0; i < nList.length; i++) {
      Count[nList[i]]--;
      if (Count[nList[i]] == 0) Q.enqueue(nList[i]);
    }
  }
}
```

# Shortest Paths

## Weighted Graphs

- Edges have weights (distance, cost, time)
- Goal: Find path with minimum total weight
- BFS only works for unweighted graphs
- Dijkstra's algorithm handles non-negative weights

## Dijkstra's Algorithm

- Single-source shortest path
- Maintain distance estimate $D(X)$
- Initialize $D(S) = 0$, all others $\infty$
- Process vertices in order of distance
- Update neighbors: $D(w) = \min(D(w), D(v) + \text{weight}(v, w))$

## Dijkstra (Simple)

- Scan all vertices to find minimum $D(v)$
- Complexity: $O(V^2)$
- Best for dense graphs

## Dijkstra (Heap)

- Use Min-Heap to find minimum $D(v)$
- Complexity: $O((V + E) \log E)$
- Best for sparse graphs

## Complexity Comparison

| Algorithm | Complexity | Best Use Case |
| --- | --- | --- |
| Dijkstra (Scan) | $\Theta(V^2)$ | Dense Graphs |
| Dijkstra (Heap) | $\Theta((V+E) \log E)$ | Sparse Graphs |

---

## Exercise

Given a set of tasks with dependencies, write a program to output a valid execution order.

## Exercise

Find the shortest path between two cities in a weighted road network using Dijkstra's algorithm.
