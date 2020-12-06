# BFS Overview

The **_Breadth First Search (BFS)_** is another fundamental search algorithm used to explore nodes and edges of a graph. It runs with a time complexity of **_O(V+E)_** and is often used as a building block in other algorithms.

The BFS algorithm is particularly useful for one thing: finding the shortest path on **_unweighted graphs_**

A BFS starts at some arbitrary node of a graph and explores the neighbor nodes first, before moving to the next level neighbors.

## Using a Queue

The BFS algorithm uses a queue data structure to track which node to visit next. Upon reaching a new node the algorithm adds it to the queue to visit it later. The queue data structure works like a real world queue such as a waiting line at a restaurant. People can either enter the waiting line (**enqueue**) or get seated (**dequeue**)

```
# Global/class scope variables
n = number of nodes in the graph
g = adjacency list representing unweighted graph

# s = start node, e = end node, and 0 <= e, s < n
function bfs(s, e):
    # Do a BFS starting at node s
    prev = solve(s)

    # Return reconstructed path from s -> e
    return reconstructPath(s, e, prev)

function solve(s):
    q = queue data structure with enqueue and dequeue
    q.enqueue(s)

    visited = [false, ..., false] # size n
    visited[s] = true

    prev = [null, ..., null] # size n

    while !q.isEmpty():
        node = q.dequeue()
        neighbors = g.get(node)

        for(next : neighbors):
            if !visited[next]:
                q.enqueue(next)
                visited[next] = true
                prev[next] = node
    return prev

function reconstructPath(s, e, prev):
    # Reconstruct path going backwards from e
    path = []
    for(at = e; at != null; at = prev[at]):
        path.add(at)

    path.reverse()

    if path[0] == s:
        return path
    return []
```

<br><br/>

# BFS Shortest Path on a Grid

## Motivation

Many problems in graph theory can be represented using a grid. Grids are a form of **_implicit graph_** because we can determine a node's neighbors based on our location within the grid.

A type of problem that involves finding a path through a grid is solving a maze

## Graph Theory on Grids

A common approach to solving graph theory problems on grids is to first convert the grid to a familiar format such as an **_adjacency list/matrix_**

### Empty Grid

First label the cells in the grid with numbers [0,n) where n = #rows x #columns. **_Note:_** Assume the grid is unweighted and cells connect left, right, up and down

| 0   | 1   |
| --- | --- |
| 2   | 3   |
| 4   | 5   |

#### Adjacency List Representation of Grid

- 0 -> [1,2]
- 1 -> [0,3]
- 2 -> [0,3,4]
- 3 -> [1,2,5]
- 4 -> [2,5]
- 5 -> [3,4]

#### Adjacency Matrix Representation of Grid

| &nbsp; | 0       | 1       | 2       | 3       | 4       | 5       |
| ------ | ------- | ------- | ------- | ------- | ------- | ------- |
| 0      | 0       | **_1_** | **_1_** | 0       | 0       | 0       |
| 1      | **_1_** | 0       | 0       | **_1_** | 0       | 0       |
| 2      | **_1_** | 0       | 0       | **_1_** | **_1_** | 0       |
| 3      | 0       | **_1_** | **_1_** | 0       | 0       | **_1_** |
| 4      | 0       | 0       | **_1_** | 0       | 0       | **_1_** |
| 5      | 0       | 0       | 0       | **_1_** | **_1_** | 0       |

Once we have an adjacency list/matrix we can run whatever specialized graph algorithm to solve our problem such as: shortest path, connected components, etc...

However, **_transformations between graph representations can usually be avoided_** due to the structure of a grid
