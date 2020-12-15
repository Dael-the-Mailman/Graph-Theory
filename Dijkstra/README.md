# Dijkstra's Shortest Path Algorithm

**_Dijkstra's algorithm_** is a Single Source Shortest Path (SSSP) algorithm for graphs with **_non-negative edge weights_**

Depending on how the algorithm is implemented and what data structures are used the time complexity is typically **_O(E\*log(V))_** which is competitive against other shortest path algorithms

One constraint for Dijkstra's algorithm is that the graph must only contain **_non-negative edge weights_**. This constraint is imposed to ensure that once a node has been visited its optimal distance cannot be improved

This property is especially important because it enables Dijkstra's algorithm to act in a greedy manner by always selecting the next most promising node.

## Quick Algorithm Overview

Maintain a 'dist' array where the distance to every node is positive infinity. Mark the distance to the start node 's' to be 0

Maintain a PQ of key-value pairs of (node index, distance) pairs which tell you which node to visite next based on sorted min value

Insert (s, 0) into the PQ and loop while PQ is not empty pulling out the next most promising (node index, distance) pair

Iterate over all edges outwards from the current node and relax each edge appending a new (node index, distance) key-value pair to the PQ for every relaxation

## Lazy Dijkstra's

```
# Runs Dijkstra's algorithm and returns an array that contains
# the shortest distance to every node from the start node s.
# g - adjacency list of weighted graph
# n - the number of nodes in the graph
# s - the index of the starting node (0 <= s < n)
function dijkstra(g, n, s):
    vis = [false, false, ..., false] # size n
    dist = [inf, inf, ... inf, inf] # size n
    dist[s] = 0
    pq = empty priority queue
    pq.insert((s, 0))
    while pq.size() != 0:
        index, minValue = pq.poll()
        vis[index] = true
        for(edge : g[index]):
            if vis[edge.to]: continue
            newDist = dist[index] + edge.cost
            if newDist < dist[edge.to]:
                dist[edge.to] = newDist
                pq.insert((edge.to, newDist))
        return dist
```

In practice most standard libraries do not support the decrease key operation for PQs. A way to get around this is to add a new (node index, best distance) pair every time we update the distance to a node

As a result, it is possible to have duplicate node indices in the PQ. This is not ideal, but inserting a new key-value pair in **_O(log(n))_** is much faster than searching for the key in the PQ which takes **_O(n)_**

A neat optimization we can do which ignores stale (index, dist) pairs in our PQ is to skip nodes where we already found a better path routing through others nodes before we got to processing this node

## Finding the optimal path

If you wish to not only find the optimal distance to a particular node but also **_what sequence of nodes were taken_** to get there you need to track some additional information

```
# Runs Dijkstra's algorithm and returns an array that contains
# the shortest distance to every node from the start node s.
# g - adjacency list of weighted graph
# n - the number of nodes in the graph
# s - the index of the starting node (0 <= s < n)
function dijkstra(g, n, s):
    vis = [false, false, ..., false] # size n
    prev = [null, null, ..., null] # size n
    dist = [inf, inf, ... inf, inf] # size n
    dist[s] = 0
    pq = empty priority queue
    pq.insert((s, 0))
    while pq.size() != 0:
        index, minValue = pq.poll()
        vis[index] = true
        for(edge : g[index]):
            if vis[edge.to]: continue
            newDist = dist[index] + edge.cost
            if newDist < dist[edge.to]:
                prev[edge.to] = index
                dist[edge.to] = newDist
                pq.insert((edge.to, newDist))
    return (dist, prev)

    # Finds the shortest path between two nodes
    # g - adjacency list of weighted graph
    # n - the number of nodes in the graph
    # s - the index of the starting node (0 <= s < n)
    # e - the index of the end node (0 <= e < n)
    function findShortestPath(g, n, s, e):
        dist, prev = dijkstra(g, n, s)
        if (dist[e] == inf) return path
        for (at = e; at != null; at = prev[at])
            path.add(at)
    path.reverse()
    return path
```

## Stopping Early

Q: Suppose you know the destination node you're trying to reach is 'e' and you start at node 's' do you still have to visit every node in the graph?

A: Yes, in the worst case. However, it is possible to stop early once you have finished visiting the destination node

The main idea for stopping early is that Dijkstra's algorihtm processes each next most promising node in order. So if the destination node has been visited, its shortest distance will not change as more future nodes are visited

```
# Runs Dijkstra's algorithm and returns the shortest distance
# between nodes 's' and 'e'. If there is no path, inf is returned
# g - adjacency list of weighted graph
# n - the number of nodes in the graph
# s - the index of the starting node (0 <= s < n)
# e - the index of the end node (0 <= e < n)
function dijkstra(g, n, s, e):
    vis = [false, false, ..., false] # size n
    dist = [inf, inf, ... inf, inf] # size n
    dist[s] = 0
    pq = empty priority queue
    pq.insert((s, 0))
    while pq.size() != 0:
        index, minValue = pq.poll()
        vis[index] = true
        for(edge : g[index]):
            if vis[edge.to]: continue
            newDist = dist[index] + edge.cost
            if newDist < dist[edge.to]:
                dist[edge.to] = newDist
                pq.insert((edge.to, newDist))
    if index == e:
        return dist[e]
    return inf
```

## Eager Dijkstra's Using an Index Priority Queue

Our current lazy implementation of Dijkstra's inserts **_duplicate key-value pairs_** (keys being the node index and the value being the shortest distance to get to that node) in our PQ because it's more efficient to insert a new key-value pair in **_O(log(n))_** than it is to update an existing key's value in **_O(n)_**

This approach is inefficient for dense graphs because we end up with **_several stale outdated key-value pairs_** in our PQ. The eager version of Dijkstra's avoids duplicate key-value pairs and supports efficient value updates in **_O(log(n))_** by using an **_Indexed Priorty Queue (IPQ)_**

```
# Runs Dijkstra's algorithm and returns an array that contains
# the shortest distance to every node from the start node s.
# g - adjacency list of weighted graph
# n - the number of nodes in the graph
# s - the index of the starting node (0 <= s < n)
function dijkstra(g, n, s):
    vis = [false, false, ..., false] # size n
    dist = [inf, inf, ... inf, inf] # size n
    dist[s] = 0
    ipq = empty indexed priority queue
    ipq.insert(s, 0)
    while pq.size() != 0:
        index, minValue = ipq.poll()
        vis[index] = true
        for(edge : g[index]):
            if vis[edge.to]: continue
            newDist = dist[index] + edge.cost
            if newDist < dist[edge.to]:
                dist[edge.to] = newDist
                if !ipq.contains(edge.to):
                    ipq.insert(edge.to, newDist)
                else:
                    ipq.decreaseKey(edge.to, newDist)
    return dist
```

## D-ary Heap Optimization

When executing Dijkstra's algorithm, especially on dense graphs, there are a lot more updates (i.e. decreaseKey operations) to key-value pairs than there are dequeue (poll) operations.

A **_D-ary heap_** is a heap variant in which each node has D children. This speeds up decrease key operations at the expense of more costly removals

## Optimal D-ary Heap Degree

Q: What is the optimal D-ary heap degree to maximize performance of Dijkstra's algorithm?

A: In general **_D = E/V_** is the best degree to use to balance removals against decreaseKey operations improving Dijkstra's time complexity to **_O(E\*log<sub>E/V</sub>(V))_** which is much better especially for dense graphs which have lots of decreaseKey operations.

## The state of the art

The current state of the art as of new is the **_Fibonacci heap_** which gives Dijkstra's algorithm a time complexity of **_O(E + Vlog(V))_**

However, in practice, Fibonacci heaps are very **_difficult to implement_** and have a **_large enough constant amortized overhead_** to make them impractical unless your graph is quite large
