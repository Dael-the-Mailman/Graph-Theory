#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

class AdjSet
{
public:
    AdjSet(int V)
    {
        this->numVertices = V;
        adj = new unordered_set<int>[V];
        visited = new bool[V];
    }
    ~AdjSet()
    {
        delete[] visited;
        delete[] adj;
    }
    void addEdge(int, int);
    void printGraph();
    void DFS(int start);

private:
    int numVertices;
    bool *visited;
    unordered_set<int> *adj;
};

void AdjSet::addEdge(int src, int dest)
{
    adj[src].insert(dest);
}

void AdjSet::printGraph()
{
    int v = numVertices;
    for (int i = 0; i < v; i++)
    {
        cout << "\n Vertex " << i << ":";
        for (auto x : adj[i])
            cout << "-> " << x;
        printf("\n");
    }
}

void AdjSet::DFS(int start)
{
    visited[start] = true;
    stack<int> s;
    s.push(start);
    printf("\n DFS: %d-> ", start);
    while (!s.empty())
    {
        start = s.top();
        s.pop();
        if (!visited[start])
        {
            cout << start << "-> ";
            visited[start] = true;
        }

        for (auto i : adj[start])
        {
            if (!visited[i])
                s.push(i);
        }
    }
}

int main()
{
    AdjSet adj(5);
    adj.addEdge(0, 1);
    adj.addEdge(0, 2);
    adj.addEdge(0, 3);
    adj.addEdge(1, 2);
    adj.addEdge(3, 4);
    adj.printGraph();
    adj.DFS(0);
    return 0;
}