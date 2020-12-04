class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for i in range(V)]
    
    def addEdge(self, src, dest):
        self.adj[src].append(dest)
    
    def printGraph(self):
        for i in range(self.V):
            print(f"\n Vertex {i}:", end='')
            for x in self.adj[i]:
                print(f"-> {x}", end='')
            print(f'\n', end='')

    def DFS(self, start):
        visited = [False for i in range(self.V)]
        stack = []
        stack.append(start)

        print(f"\n DFS: ", end='')

        while (len(stack)):
            start = stack.pop()
            
            if (not visited[start]):
                print(f'{start}-> ',end='')
                visited[start] = True
            
            for i in self.adj[start]:
                if (not visited[i]):
                    stack.append(i)

if __name__ == '__main__':
    adj = Graph(5)
    adj.addEdge(0, 1)
    adj.addEdge(0, 2)
    adj.addEdge(0, 3)
    adj.addEdge(1, 2)
    adj.addEdge(3, 4)
    adj.printGraph()
    adj.DFS(0)