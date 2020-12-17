import heapq
import sys

class Graph:
    def __init__(self, size):
        self.V = size
        self.adj = [[] for i in range(size)]
    
    def addEdge(self, src, dest, w):
        self.adj[src].append((dest, w))

    def dijkstra(self, src):
        dist = [sys.maxsize] * self.V
        dist[src] = 0
        q = [(0, src)]

        while len(q):
            weight, vertex = heapq.heappop(q)
            
            for v,w in self.adj[vertex]:
                v = int(v)
                vertex = int(vertex)
                if dist[v] > dist[vertex] + w:
                    if dist[v] != sys.maxsize:
                        q.remove((dist[v], v))
                        # heapq.heapify(q)
                    
                    dist[v] = dist[vertex] + w
                    heapq.heappush(q, (dist[v], v))

        print(f"List of the Shortest Distances from node {src} to all other nodes:")
        for index, weight in enumerate(dist):
            print(f"\tVertex: {index}\tDistance: {weight}")

if __name__ == '__main__':
    g = Graph(9)
    g.addEdge(0, 1, 4)
    g.addEdge(0, 7, 8)
    g.addEdge(1, 2, 8)
    g.addEdge(1, 7, 11)
    g.addEdge(2, 3, 7)
    g.addEdge(2, 8, 2)
    g.addEdge(2, 5, 4)
    g.addEdge(3, 4, 9)
    g.addEdge(3, 5, 14)
    g.addEdge(4, 5, 10)
    g.addEdge(5, 6, 2)
    g.addEdge(6, 7, 1)
    g.addEdge(6, 8, 6)
    g.addEdge(7, 8, 7)
    g.dijkstra(0)