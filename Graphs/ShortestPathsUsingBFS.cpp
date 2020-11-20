#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> l;
    void DFSRecHelper(T root, set<T> &visited)
    {
        if (visited.find(root) == visited.end())
        {
            cout << root << " ";
            visited.insert(root);

            for (T nbr : l[root])
            {
                DFSRecHelper(nbr, visited);
            }
        }
    }

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
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

    // void BFS(T src)
    // {
    //     cout << endl;
    //     set<T> visited;
    //     queue<T> q;

    //     q.push(src);
    //     visited.insert(src);
    //     while (!q.empty())
    //     {
    //         T curNode = q.front();
    //         cout << curNode << " ";
    //         q.pop();

    //         for (T nbr : l[curNode])
    //         {
    //             if (visited.find(nbr) == visited.end())
    //             {
    //                 q.push(nbr);
    //                 visited.insert(nbr);
    //             }
    //         }
    //     }
    // }

    int shortestPath(T src, T target)
    {
        if (src == target)
        {
            return 0;
        }

        queue<T> q;
        set<T> visited;

        q.push(src);
        visited.insert(src);
        int pathLength = 0;
        bool found = false;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {

                T curNode = q.front();
                q.pop();
                if (curNode == target)
                {
                    found = true;
                    return pathLength;
                }

                for (T nbr : l[curNode])
                {
                    if (visited.find(nbr) == visited.end())
                    {
                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
            pathLength++;
        }

        if (!found)
        {
            return -1;
        }
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(2, 5);
    g.addEdge(5, 4);
    g.addEdge(6, 4);
    g.addEdge(6, 5);

    int length = g.shortestPath(2, 3);

    cout << length;
}