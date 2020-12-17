#include <iostream>
#include <limits>
#include <climits>
#include <list>

using namespace std;

typedef pair<int, double> edge;

const long double INF = numeric_limits<long double>::infinity();

class Graph
{
public:
    Graph(int size)
    {
        V = size;
        adj = new list<edge>[size];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int src, int dest, double weight)
    {
        adj[src].push_back(make_pair(dest, weight));
        // uncomment for undirected graph
        // adj[dest].push_back(make_pair(src, weight));
    }

    void bellmanford(int src)
    {
        double dist[V];
        // int prev[V];

        for (int i = 0; i < V; i++)
        {
            dist[i] = INF;
            // prev[i] = INT_MAX;
        }

        dist[src] = 0;

        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
            {
                if (dist[x.first] > dist[i] + x.second)
                {
                    dist[x.first] = dist[i] + x.second;
                    // prev[x.first] = i;
                }
                if (dist[i] + x.second < dist[x.first])
                    cout << "Graph contains a negative-weight cycle" << '\n';
            }
        }

        printf("List of the Shortest Distances from node %d to all other nodes:\n", src);
        for (int i = 0; i < V; i++)
        {
            printf("\tVertex: %d\tDistance: %f\n", i, dist[i]);
        }
    }

private:
    int V;
    list<edge> *adj;
};

int main()
{
    Graph g(9);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.bellmanford(0);
    return 0;
}