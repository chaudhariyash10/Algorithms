#include <bits/stdc++.h>

using namespace std;

//n < 1000 && w < 1000
int dp[1001][1001];

int knapsack(int val[], int wt[], int W, int n)
{
    for (int i = 0; i < 1001; i++)
    {
        dp[i][0] = dp[0][i] = 0;
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < W+1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
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