#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;

    void fillOrder(int v, stack<int> &Stack, bool visited[]);
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int v);
    void addEdge(int x, int y);
    Graph getTranspose();
    int printSCCs();
};

Graph Graph::getTranspose()
{
    Graph GT(V);

    for (int i = 0; i < V; i++)
    {
        for (int nbr : adj[i])
        {
            GT.addEdge(nbr, i);
        }
    }

    return GT;
}

void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y);
}

Graph::Graph(int v)
{
    this->V = v;
    this->adj = new list<int>[v];
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    for (int nbr : adj[v])
    {
        if (visited[nbr] != true)
        {
            this->DFSUtil(nbr, visited);
        }
    }
}

void Graph::fillOrder(int v, stack<int> &Stack, bool visited[])
{
    visited[v] = true;

    for (int nbr : adj[v])
        if (visited[nbr] == false)
            this->fillOrder(nbr, Stack, visited);

    Stack.push(v);
}
int Graph::printSCCs()
{
    stack<int> Stack;

    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] != true)
            fillOrder(i, Stack, visited);

    Graph Gt = this->getTranspose();

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    int noOfConnectedComponents = 0;
    while (Stack.empty() == false)
    {
        int z = Stack.top();
        Stack.pop();

        if (visited[z] == false)
        {
            Gt.DFSUtil(z, visited);
            cout << endl;
            noOfConnectedComponents++;
        }
    }
    return noOfConnectedComponents;
}
int main()
{
    Graph G(9);

    G.addEdge(0, 6);
    G.addEdge(6, 8);
    G.addEdge(6, 3);
    G.addEdge(3, 0);
    G.addEdge(2, 8);
    G.addEdge(5, 7);
    G.addEdge(8, 5);
    G.addEdge(5, 2);
    G.addEdge(7, 1);
    G.addEdge(1, 4);
    G.addEdge(4, 7);
    cout << "Following are strongly connected components in "
            "given graph \n";
    cout << G.printSCCs() << " SCCs are present in graph";

    return 0;
}