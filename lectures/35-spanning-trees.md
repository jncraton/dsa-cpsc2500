---
reading: '[Minimal Cost Spanning Trees](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/MCST.html), [Kruskal’s Algorithm](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/Kruskal.html)'
teaching_goal: Students will understand the concept of Minimal Cost Spanning Trees and the mechanics of Prim's and Kruskal's algorithms.
learning_objectives:
  - Define a Minimal Cost Spanning Tree (MCST)
  - Explain the greedy approach of Prim's algorithm
  - Explain the greedy approach of Kruskal's algorithm
  - Compare the complexity and mechanics of both algorithms
---

# Spanning Trees

## Definition

- A spanning tree connects all vertices
- It contains no cycles
- For $n$ vertices, it has $n-1$ edges
- It is a "free" tree spanning the graph

## Minimal Cost

- Each edge has a weight (cost)
- MCST minimizes the sum of weights
- No cycle can be formed by the edges
- Removing any edge from a cycle allows for a cheaper tree

## Applications

- Soldering wires on a circuit board
- Connecting cities with telephone lines
- Laying cable for a network
- Minimizing infrastructure costs

## Prim's Algorithm

- A greedy algorithm
- Starts from a single vertex
- Grows the tree one vertex at a time
- Picks the cheapest edge connecting a visited vertex to an unvisited one

## Prim's Mechanics

- Maintain a set of visited vertices
- At each step, find the minimum weight edge
- Edge must connect visited to unvisited
- Add the new vertex to the visited set
- Repeat until all vertices are visited

## Prim's vs Dijkstra

- Both are greedy
- Dijkstra: shortest path from a source
- Prim: minimum cost to connect all vertices
- Prim's update: $D[w] = \min(D[w], \text{weight}(v, w))$
- Dijkstra's update: $D[w] = \min(D[w], D[v] + \text{weight}(v, w))$

## Prim's Complexity

- Using a priority queue
- Time: $O(E \log V)$
- Space: $O(V)$ to store distances and parents

## Kruskal's Algorithm

- A greedy algorithm
- Processes edges in increasing order of weight
- Uses a Disjoint Set (Union-Find)
- Adds edge if it connects two different components

## Kruskal's Mechanics

- Initialize each vertex as its own set
- Sort all edges by weight
- For each edge $(u, v)$:
  - If $u$ and $v$ are in different sets:
    - Add edge to MCST
    - Union the sets of $u$ and $v$
- Stop when $n-1$ edges are added

## Kruskal's Complexity

- Time: $O(E \log E)$ or $O(E \log V)$
- Sorting edges dominates the cost
- Union-Find operations are nearly constant

## Comparison

| Feature | Prim's | Kruskal's |
| --- | --- | --- |
| Strategy | Vertex-centric | Edge-centric |
| Growth | Grows from a root | Grows as a forest |
| Data Structure | Priority Queue | Union-Find |
| Best for | Dense graphs | Sparse graphs |

---

## Exercise

Given a graph with 5 vertices and 7 edges, describe the steps to find the MCST using Kruskal's algorithm.

## Exercise

Explain why Prim's algorithm is similar to Dijkstra's algorithm but with a different update rule.
