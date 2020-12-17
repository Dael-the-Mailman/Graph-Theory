# Floyd-Warshall Algorithm

In graph theory, the **_Floyd-Warshall (FW)_** algorithm is an **_All-Pairs Shortest Path (APSP)_** algorithm. This means it can find the shortest path between all pairs of nodes.

The time complexity to run FW is **_O(V<sup>3</sup>)_** which is \*\*\_ideal for graphs no larger than a couple hundred nodes

## Shortest Path (SP) Algorithms

| &nbsp;                            | BFS                             | Dijkstra's     | Bellman Ford | Floyd Warshall |
| --------------------------------- | ------------------------------- | -------------- | ------------ | -------------- |
| Recommended graph size            | Large                           | Large/Medium   | Medium/Small | Small          |
| Good for APSP                     | Only works on unweighted graphs | Ok             | Bad          | Yes            |
| Can detect negative cycles?       | No                              | No             | Yes          | Yes            |
| SP on graph with weighted edges   | Incorrect SP answer             | Best algorithm | Works        | Bad in general |
| SP on graph with unweighted edges | Best algorithm                  | Ok             | Bad          | Bad in general |
