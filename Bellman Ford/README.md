# Bellman-Ford Algorithm

In graph theory, the **_Bellman-Ford (BF)_** algorithm is a **_Single Source Shortest Path (SSSP)_** algorithm. This means it can find the shortest path from one node to any other node.

However, BF is not ideal for most SSSP problems because it has a time complexity of **_O(EV)_**. It is better to use Dijkstra's algorithm which is much faster. It is on the order of **_O((E+V)log(V))_** when using a binary heap priority queue.

However, Dijkstra's algorithm can fail when the graph has negative edge weights. This is when BF becomes really handy because it can be used to detect **_negative cycles_** and **_determine where they occur_**

Finding negative cycles can be useful in many types of applications. One particularly neat application aries in finace when performing an **_arbitrage_** between two or more markets

## Pseudocode

```
# From Wikipedia
function BellmanFord(list vertices, list edges, vertex source) is

    // This implementation takes in a graph, represented as
    // lists of vertices (represented as integers [0..n-1]) and edges,
    // and fills two arrays (distance and predecessor) holding
    // the shortest path from the source to each vertex

    distance := list of size n
    predecessor := list of size n

    // Step 1: initialize graph
    for each vertex v in vertices do
        distance[v] := inf             // Initialize the distance to all vertices to infinity
        predecessor[v] := null         // And having a null predecessor

    distance[source] := 0              // The distance from the source to itself is, of course, zero

    // Step 2: relax edges repeatedly
    repeat |V|−1 times:
        for each edge (u, v) with weight w in edges do
            if distance[u] + w < distance[v] then
                distance[v] := distance[u] + w
                predecessor[v] := u

    // Step 3: check for negative-weight cycles
    for each edge (u, v) with weight w in edges do
        if distance[u] + w < distance[v] then
            error "Graph contains a negative-weight cycle"

    return distance, predecessor
```
