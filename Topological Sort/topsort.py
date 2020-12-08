import sys

INF = sys.maxsize

class Graph:
    def __init__(self, size):
        self.V = size
        self.adj = [[] for i in range(size)]
        self.top_order = [0]*size
        self.calculated = False
    
    def addEdge(self, src, dest, w):
        self.adj[src].append((dest, w))
    
    def printGraph(self):
        for src in range(self.V):
            print(f"\n Vertex {src}:", end='')
            for tup in self.adj[src]:
                print(f"-> {tup[0]} weight: {tup[1]}", end='')
            print("\n", end='')

    def topsort(self, printOrder=False):
        in_degree = [0]*self.V

        for u in range(self.V):
            for x in self.adj[u]:
                in_degree[x[0]] += 1
        
        q = []
        for i in range(self.V):
            if(in_degree[i] == 0):
                q.append(i)
        
        count = 0

        while(len(q)):
            u = q.pop(0)

            try:
                self.top_order[count] = u
                for x in self.adj[u]:
                    in_degree[x[0]] -= 1
                    if in_degree[x[0]] == 0:
                        q.append(x[0])
                count += 1
            except Exception as e:
                print("\nThere's a cycle in the graph")
        
        if printOrder:
            print("\n Topological Order: ", end='')
            for i in self.top_order:
                print(f"{i}-> ", end='')
            print("\n", end='')

        self.calculated = True

    def shortestPath(self, start, end):
        if(not self.calculated):
            self.topsort()
        dist = [INF]*self.V
        dist[start] = 0

        for i in range(self.V):
            index = self.top_order[i]
            if dist[index] != INF:
                edges = self.adj[index]
                for e in edges:
                    newDist = dist[index] + e[1]
                    dist[e[0]] = min(dist[e[0]], newDist)

        if (dist[end] >= INF):
            print(f"\nNode {end} is unreachable from node {start}")
            return
        print(f"\nShortest Distance from node {start} to node {end} is {dist[end]}")
    
    def longestPath(self, start, end):
        if(not self.calculated):
            self.topsort()
        dist = [INF]*self.V
        dist[start] = 0

        for i in range(self.V):
            index = self.top_order[i]
            if dist[index] != INF:
                edges = self.adj[index]
                for e in edges:
                    newDist = dist[index] - e[1]
                    dist[e[0]] = min(dist[e[0]], newDist)

        if (dist[end] >= INF):
            print(f"\nNode {end} is unreachable from node {start}")
            return
        print(f"\nLongest Distance from node {start} to node {end} is {-dist[end]}")

if __name__ == '__main__':
    g = Graph(7)
    g.addEdge(0, 1, 3)
    g.addEdge(0, 2, 2)
    g.addEdge(0, 5, 3)
    g.addEdge(1, 3, 1)
    g.addEdge(1, 2, 6)
    g.addEdge(2, 3, 1)
    g.addEdge(2, 4, 10)
    g.addEdge(3, 4, 5)
    g.addEdge(5, 4, 7)
    g.printGraph()
    g.topsort(True)
    g.shortestPath(0,4)
    g.longestPath(0,4)
    g.shortestPath(0,6)