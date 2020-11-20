#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Graph
{
    int V;
    map<T, list<T>> l;

public:
    Graph()
    {
        V = 0;
    }
    void addEdge(T x, T y)
    {
        if (l.find(x) == l.end())
            V++;
        if (l.find(y) == l.end())
            V++;

        l[x].push_back(y);
        l[y].push_back(x);
    }
    void addVertex(T v)
    {
        list<T> k;
        l[v] = k;
    }
    void print()
    {
        for (pair<T, list<T>> i : l)
        {
            cout << "\nValue: " << i.first << "->neighbours: ";
            for (T j : i.second)
            {
                cout << " " << j;
            }
        }
    }

    void BFSUtil(T src, set<T> &visited)
    {
        queue<T> q;

        q.push(src);

        while (!q.empty())
        {
            T curNode = q.front();
            q.pop();

            for (T nbr : l[curNode])
            {
                if (visited.find(nbr) == visited.end())
                {
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }
    }

    int numberOfConnectedComponents()
    {
        int vertices = V;
        set<T> visited;
        int count = 0;
        for (pair<T, list<T>> vertex : l)
        {
            if (visited.find(vertex.first) == visited.end())
            {
                visited.insert(vertex.first);
                BFSUtil(vertex.first, visited);
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1, 5);
    g.addEdge(0, 2);
    g.addEdge(2, 4);

    g.addVertex(3);
    g.addEdge(3, 7);
    g.print();
    int length = g.numberOfConnectedComponents();

    cout << endl
         << length;
}