#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, list<int>> adj;
    void topologicalSortUtil(int v, stack<int> &st, set<int>& visited);

public:
    void addEdge(int x, int y);
    void topologicalSort();
};

void Graph::addEdge(int x, int y)
{
    adj[x].push_back(y);
}


void Graph::topologicalSortUtil(int cur, stack<int> &st, set<int> &visited)
{
    if (visited.find(cur) != visited.end())
    {
        return;
    }

    visited.insert(cur);

    for (int i : adj[cur])
    {
        if (visited.find(i) == visited.end())
            topologicalSortUtil(i, st, visited);
    }

    st.push(cur);
}

void Graph::topologicalSort()
{
    set<int> visited;
    stack<int> st;

    for (pair<int, list<int>> cur : adj)
    {
        if (visited.find(cur.first) == visited.end())
            topologicalSortUtil(cur.first, st, visited);
    }
    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    Graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}