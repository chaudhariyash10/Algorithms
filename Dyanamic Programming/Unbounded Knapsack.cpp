#include <bits/stdc++.h>

using namespace std;
//Rod Cutting Problem is exactly the same as Unbouunded knapsack.

//n < 1000 && w < 1000
int dp[1001][1001];

int knapsack(int val[], int wt[], int W, int n)
{
    dp[0][0] = true;

    for (int i = 1; i < 1001; i++)
    {
        dp[i][0] = true;
        dp[0][i] = false;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (val[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - val[i - 1]]);
        }
    }

    return dp[n][W];
}

int main()
{
    int val[] = {1, 2, 4, 5, 4, 8};
    int wt[] = {1, 2, 3, 5, 6, 7};
    int n = 6;
    int W = 6;

    cout << knapsack(val, wt, W, n);
}