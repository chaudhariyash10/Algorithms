#include <stdc++.h>

using namespace std;
class Solution
{

    map<int, list<int>> l;

public:
    pair<bool, int> DFS_helper(int src, unordered_map<int, bool> &visited, int target, vector<int> &val)
    {
        int curGCD = val[src];
        if (visited[src])
            return make_pair(true, val[src]);

        if (target == src)
            return make_pair(false, val[src]);

        visited[src] = true;

        bool ans = true;
        for (auto nbr : l[src])
        {

            pair<bool, int> ans = DFS_helper(nbr, visited, target, val);

            if (!ans.first)
                return ans;
            curGCD = gcd(curGCD, ans.second);
        }

        return make_pair(ans, curGCD);
    }

    pair<bool, int> DFS(int x, int y, vector<int> &val)
    {
        unordered_map<int, bool> visited;

        return DFS_helper(x, visited, y, val);
    }
    int gcd(int a, int b)
    {

        if (b == 0)
        {
            return a;
        }
        else
        {
            return gcd(b, a % b);
        }
    }
    int gcdTree(int n, vector<vector<int>> &edges, vector<int> &val, int x, int y)
    {

        for (int i = 0; i < edges.size(); i++)
        {
            l[edges[i][0]].push_back(edges[i][1]);
        }

        pair<bool, int> XY = DFS(x, y, val);
        pair<bool, int> YX = DFS(y, x, val);

        if ((XY.first && YX.first) == false)
            return -1;

        else
        {
            return gcd(XY.second, YX.second);
        }
    }
};

int main()
{
    int N = 5, X = 2, Y = 1;
    vector<vector<int>> edges{{0, 1}, {0, 2}, {1, 4}, {2, 3}};

    vector<int> val{30, 24, 10, 20, 16};
    Solution obj;
    cout << obj.gcdTree(N, edges, val, X, Y);
}