#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, list<int>> adj;
    bool isCyclicUtil(int v, bool visited[], bool recStack[]);

public:
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y];
    }
    bool isCyclic();
};

bool Graph::isCyclicUtil(int v, bool visited[], bool recStack[])
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for(int i : adj[v])
        {
            if(!visited[i] && isCyclicUtil(v, visited, recStack))
                return true;
            else if(recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[adj.size()];
    bool *recStack = new bool[adj.size()];

    for (int i = 0; i < adj.size(); i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (pair<int, list<int>> cur : adj)
        if (isCyclicUtil(cur.first, visited, recStack))
            return true;

    return false;
}

int main()
{
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<g.isCyclic();
}