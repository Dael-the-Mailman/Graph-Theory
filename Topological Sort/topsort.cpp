#include <iostream>
#include <utility>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef pair<int, int> edge;

class Graph
{
public:
    Graph(int size) : V(size)
    {
        adj = new list<edge>[size];
        top_order = new int[size];
        isCalculated = false;
    }

    ~Graph()
    {
        delete[] adj;
        delete[] top_order;
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "\n Vertex " << i << ":";
            for (auto x : adj[i])
                printf("-> %d weight: %d", x.first, x.second);
            printf("\n");
        }
    }

    void addEdge(int src, int dest, int weight)
    {
        this->adj[src].push_back(make_pair(dest, weight));
    }

    void topsort(bool print = false)
    {
        int in_degree[V]{};

        for (int u = 0; u < V; u++)
            for (auto x : adj[u])
                in_degree[x.first]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (in_degree[i] == 0)
                q.push(i);

        int count = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            try
            {
                top_order[count] = u;
                for (auto x : adj[u])
                    if (--in_degree[x.first] == 0)
                        q.push(x.first);

                count++;
            }
            catch (const exception &e)
            {
                cout << "There's a cycle in the graph" << '\n';
            }
        }

        if (print)
        {
            cout << "\nTopological Order: ";
            for (int i = 0; i < V; i++)
            {
                printf("%d-> ", top_order[i]);
            }
            cout << '\n';
        }
        isCalculated = true;
    }

    void shortestPath(int start, int end)
    {
        if (!isCalculated)
            topsort();
        int dist[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;
        dist[start] = 0;

        for (int i = 0; i < V; i++)
        {
            int index = top_order[i];
            if (dist[index] != INT_MAX)
            {
                list<edge> edges = adj[index];
                for (edge e : edges)
                {
                    int newDist = dist[index] + e.second;
                    dist[e.first] = min(dist[e.first], newDist);
                }
            }
        }

        if (dist[end] == INT_MAX)
        {
            printf("\nNode %d is unreachable from node %d\n", end, start);
            return;
        }
        printf("\nShortest Distance from node %d to node %d is %d\n", start, end, dist[end]);
    }

    void longestPath(int start, int end)
    {
        if (!isCalculated)
            topsort();
        int dist[V];
        for (int i = 0; i < V; i++)
            dist[i] = INT_MAX;
        dist[start] = 0;

        for (int i = 0; i < V; i++)
        {
            int index = top_order[i];
            if (dist[index] != INT_MAX)
            {
                list<edge> edges = adj[index];
                for (edge e : edges)
                {
                    int newDist = dist[index] - e.second;
                    dist[e.first] = min(dist[e.first], newDist);
                }
            }
        }

        if (dist[end] == INT_MAX)
        {
            printf("\nNode %d is unreachable from node %d\n", end, start);
            return;
        }
        printf("\nLongest Distance from node %d to node %d is %d\n", start, end, -dist[end]);
    }

private:
    const int V;
    list<edge> *adj;
    int *top_order;
    bool isCalculated;
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 5, 3);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 2, 6);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 5);
    g.addEdge(5, 4, 7);
    g.printGraph();
    g.topsort(true);
    g.shortestPath(0, 4);
    g.longestPath(0, 4);
    g.shortestPath(0, 6);
}