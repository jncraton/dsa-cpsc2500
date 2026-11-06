---
reading: '[Graph Introduction](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/GraphIntro.html), [Graph Implementations](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/GraphImpl.html)'
teaching_goal: Students will understand graph terminology and the two primary ways to represent graphs in memory.
learning_objectives:
  - Define vertices, edges, and degrees
  - Distinguish between directed and undirected graphs
  - Compare adjacency matrix and adjacency list representations
  - Analyze space and time complexity for both representations
---

# Graphs

## Definition

- A graph $G = (V, E)$
- $V$ is a set of vertices (nodes)
- $E$ is a set of edges (connections)
- Edges connect pairs of vertices

## Terminology

- Incident: Edge connects a vertex
- Adjacen*: Two vertices connected by an edge
- Degree: Number of edges incident to a vertex
- Path: Sequence of vertices connected by edges
- Cycle: Path that starts and ends at the same vertex

## Directed vs Undirected

- Undirected: Edges have no direction
- Directed (Digraph): Edges have a specific direction
- In-degree: Number of edges coming into a vertex
- Out-degree: Number of edges going out from a vertex

## Weighted Graphs

- Edges can have associated costs or weights
- Weights represent distance, time, or capacity
- Weights are stored within the representation

## Sparse vs Dense

- Sparse: Few edges relative to vertices
- Dense: Many edges relative to vertices
- Complete: Every vertex connected to every other vertex
- Clique: Subgraph where all vertices are connected

## Adjacency Matrix

- A $|\mathbf{V}| \times |\mathbf{V}|$ 2D array
- `matrix[i][j]` stores weight of edge $(i, j)$
- Space complexity: $\Theta(|\mathbf{V}|^2)$
- Good for dense graphs
- Fast edge lookups: $O(1)$

## Adjacency List

- An array of linked lists
- Each index $i$ stores a list of neighbors for vertex $i$
- Space complexity: $\Theta(|\mathbf{V}| + |\mathbf{E}|)$
- Good for sparse graphs
- Efficient for iterating over neighbors

## Comparison

| Feature | Adjacency Matrix | Adjacency List |
| --- | --- | --- |
| Space | $\Theta(|\mathbf{V}|^2)$ | $\Theta(|\mathbf{V}| + |\mathbf{E}|)$ |
| Edge Lookup | $O(1)$ | $O(\text{degree}(v))$ |
| Neighbor Iteration | $O(|\mathbf{V}|)$ | $O(\text{degree}(v))$ |
| Best Use Case | Dense Graphs | Sparse Graphs |

## Exercise

Given a graph with 5 vertices and 3 edges, calculate the total space required for an adjacency matrix if each entry is 4 bytes.

## Exercise

Which representation is better for a social network with 1 million users where each user has an average of 100 friends?
