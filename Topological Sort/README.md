# Topological Sort

Many real world situations can be modelled as a graph with directed edges where some events must occur before others.

- School class prerequisites
- Program dependencies
- Event scheduling
- Assembly instructions
- Etc...

A **_topological ordering_** is an ordering of the nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B in the ordering.

the **_topological sort_** algorithm can find a topological ordering in **_O(V+E)_** time

**NOTE**: Topological orderings are NOT unique

## Directed Acyclic Graphs (DAG)

Not every graph can have a topological ordering. A graph which contains a cycle cannot have a valid ordering

The only type of graph which has a valid topological ordering is a **_Directed Acyclic Graph (DAG)_**. These are graphs with directed edges and no cycles.

Q: How do I verify that my graph does not contain a directed cycle?

A: One method is to use a Tarjan's strongly connected component algorithm which can be used to find these cycles.

By definition, all rooted trees have a topological ordering since they do not contain any cycles

## Topological Sort Algorithm

1. Pick an unvisited node
2. Beginning with the selected node, do a Depth First Search (DFS) exploring only unvisited nodes.
3. On the recursive callback of the DFS, add the current node to the topological ordering in reverse order

```
# Assumption: graph is stored as adjacency list
function topsort(graph):
    N = graph.numberOfNodes()
    V = [false,...,false] # Length N
    ordering = [0,...,0]
    i = N - 1 # Index for ordering array

    for(at = 0; at < N; at++):
        if V[at] == false:
            visitedNodes = []
            dfs(at, V, visitedNodes, graph)
            for nodeId in visitedNodes:
                ordering[i] = nodeId
                i = i - 1
    return ordering

    function dfs(at, V, visitedNodes, graph):
        V[at] = true

        edges = graph.getEdgesOutFromNode(at)
        for edge in edges:
            if V[edge.to] == false:
                dfs(edge.to, V, visitedNodes, graph)
        visitedNodes.add(at)
```

## Topsort Optimization

```
function topsort(graph):
    N = graph.numberOfNodes()
    V = [false,...,false] # Length N
    ordering = [0,...,0] # Length N
    i = N - 1 # Index for ordering array

    for(at = 0; at < N; at++){
        if V[at] == false:
            i = dfs(i, at, V, ordering, graph)
    }

    return ordering
    function dfs(at, V, ordering, graph):
        V[at] = true

        edges = graph.getEdgesOutFromNode(at)
        for edge in edges:
            if V[edge.to] == false:
                i = dfs(edge.to, V, ordering, graph)
        ordering[i] = at
        return i - 1
```

<br></br>

# Shortest and Longest Paths on DAGs

## SSSP on DAG

The **_Single Source Shortest Path (SSSP)_** problem can be solved efficiently on a DAG in **_O(V+E)_** time. This is due to the fact that the nodes can be ordered in a **_topological ordering_** via topsort and processed sequentially.

## Longest Path on DAG

What about the longest path? On a general graph this problem is **_NP-Hard_**, but on a DAG this problem in solvable in **_O(V+E)_**

The trick is to multiply all edge values by -1 then find the shortest path then multiply the edge values by -1 again
