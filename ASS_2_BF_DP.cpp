#include <iostream>
#include <algorithm>
using namespace std;

struct Graph
{
    int source, destination, weight;
};

void printOutput(int dist[], int v)
{
    cout << "Vertex"
         << "\t"
         << "Distance from source vertex" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

void Bellman_Ford(Graph g[], int sourceV, int v, int e)
{
    int dist[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[sourceV] = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = g[j].source;
            int v = g[j].destination;
            int w = g[j].weight;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < e; i++)
    {
        int u = g[i].source;
        int v = g[i].destination;
        int w = g[i].weight;
        if (dist[u] + w < dist[v])
        {
            cout << "Negative cycle is present" << endl;
        }
    }
    printOutput(dist, v);
    return;
}

int main()
{

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph graph[E];

    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cout << "Enter source, destination and weight: ";
        cin >> s >> d >> w;
        graph[i].source = s;
        graph[i].destination = d;
        graph[i].weight = w;
    }

    Bellman_Ford(graph, 0, V, E);
    return 0;
}