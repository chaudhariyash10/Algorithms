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

    void DFSRec(T root)
    {
        cout << endl;
        set<T> visited;
        DFSRecHelper(root, visited);
    }

    void DFSIter(T src)
    {
        cout << endl;
        stack<T> st;
        set<T> visited;
        st.push(src);
        visited.insert(src);
        while (!st.empty())
        {

            T curNode = st.top();

            cout << curNode << " ";

            st.pop();

            for (T nbr : l[curNode])
            {
                if (visited.find(nbr) == visited.end())
                {
                    st.push(nbr);
                    visited.insert(nbr);
                }
            }
        }
    }

    void BFSIter(T src)
    {
        cout << endl;
        set<T> visited;
        queue<T> q;

        q.push(src);
        visited.insert(src);
        while (!q.empty())
        {
            T curNode = q.front();
            cout << curNode << " ";
            q.pop();

            for (T nbr : l[curNode])
            {
                if (visited.find(nbr) == visited.end())
                {
                    q.push(nbr);
                    visited.insert(nbr);
                }
            }
        }
    }

    void BFSRec(T src)
    {
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 4);
    g.addEdge(5, 0);
    g.print();

    g.BFSIter(3);
}