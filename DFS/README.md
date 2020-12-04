# DFS Overview

The **_Depth First Search (DFS)_** is the most fundemental search algorithm used to explore nodes and edges of a graph. It runs with a time complexity of **_O(V+E)_** and is often used as a building block in other algorithms

By itself the DFS isn't all that useful, but **_when augmented_** to perform other tasks such as count connected components, determine connectivity, or find bridges/articulation points then **_DFS really shines_**

## Basic DFS

As the name suggests, a DFS plunges depth first into a graph without regard for which edge it takes next until it cannot go any further at which point it backtracks and continues

Steps:

1. Start DFS at any node
2. Pick an edge outwards from initial node
3. Pick an edge outward from chosen node
4. Repeat 2 and 3 until algorithm reaches an end node or revisits previous node
5. Backtrack to previous node and repeat 2-4 until entire graph has been explored

## Pseudocode

```
# Global or class scope variables
n = number of nodes in the graph
g = adjacency list representing graph
visited = [false, ..., false] # size n

function dfs(at):
    if visited[at]: return
    visited[at] = true

    neighbors = graph[at]
    for next in neighbors:
        dfs(next)

# Start DFS at node zero
start_node = 0
dfs(start_node)
```

## Connected Components

Sometimes a graph is split into multiple components. It's useful to be able to identify and count these components

We can use a DFS to identify components. First, make sure all the nodes are labeled from [0,n) where n is the number of nodes.

Algorithm: Start a DFS at every node (except if it's already been visisted) and mark all reachable nodes as being part of the same component.

```
# Global or class scope variables
n = number of nodes in the graph
g = adjacency list representing graph
count = 0
components = empty integer array # size n
visited = [false, ..., false] # size n

function findComponents():
    for (i = 0; i < n; i++):
        if !visited[i]:
            count++
            dfs(i)
    return (count, components)

function dfs(at):
    visited[at] = true
    components[at] = count
    for (next : g[at]):
        if !visited[next]:
            dfs(next)
```

## What else can DFS do?

We can augment the DFS algorithm to:

- Compute a graph's minimum spanning tree
- Detect and find cycles in a grpah
- Check if a graph is bipartite
- Find strongly connected components
- Topologically sort the nodes of a graph
- Find bridges and articulation points
- Find augmenting paths in a flow networks
- Generate mazes
