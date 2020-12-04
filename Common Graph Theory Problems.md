# Common Problems in Graph Theory

## Questions that should be asked

- Is the graph directed or undirected?
- Are the edges of the graph weighted?
- Is the graph likely to be sparse or dense with edges?
- Should I use an adjacency matrix, adjacency list, an edge list or other structure to represent the graph efficiently?

<br></br>

## Shortest Path Problem

Given a weighted graph, find the shortest path of edges from node A to node B.

Algorithms Used:

- BFS (unweighted graph)
- Dijkstra's,
- Bellman-Ford
- Floyd-Warshall,
- A\*
- Others

<br></br>

## Connectivity

Does there exist a path between node A and node B?

Typical solution: Use union find data structure or any search algorithm (e.g. DFS)

<br></br>

## Negative Cycles

Does my weighted graph have any negative cycles? If so, where?

Algorithms Used:

- Bellman-Ford
- Floyd-Warshall

<br></br>

## Strongly Connected Components

Strongly Connected Components (SCCs) can be thought of as self-contained cycles within a directed graph where every vertex in a given cycle can reach every other vertex in the same cycle.

Algorithms Used:

- Tarjan's algorithm
- Kosaraju's algorithm

<br></br>

## Traveling Salesman Problem

Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?

Algorithms:

- Held-Karp, branch and bound and many approximation algorithms

<br></br>

## Bridges

A **_bridge / cut edge_** is any edge in a graph whose removal increases the number of connected components

Bridges are important in graph theory because they often hint at weak points, bottlenecks or vulnerabilities in a graph

<br></br>

## Articulation points

An **_articulation point / cut vertex_** is any node in a graph whose removal increases the number of connected components

Articulation points are important in graph theory because they often hint at weak points, bottlenecks, or vulnerabilities in a graph

<br></br>

## Minimum Spanning Tree(MST)

A **_minimum spanning tree (MST)_** is a subset of the edges of a connected, edge-weighted graph that connects all the verticies together, without any cycles and with the minimum possible total edge weight.

Algorithms Used:

- Kruskal's algorithm
- Prim's & Boruvka's algorithm

<br></br>

## Network flow: max flow

With an infinite input source how much "flow" can we push through the network?

Algorithms Used:

- Ford-Fulkerson
- Edmonds-Karp
- Dinic's algorithm
