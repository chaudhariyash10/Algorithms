#include <bits/stdc++.h>

using namespace std;

int minimumNumberOfCoinsRequired(int coins[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = INT_MAX - 1;

    for (int i = 1; i < n + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < sum + 1; i++)
        if (i % coins[0] == 0)
            dp[1][i] = i / coins[0];
        else
            dp[1][i] = INT_MAX - 1;

    for (int i = 2; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
        }

    return dp[n][sum];
}
int main()
{
    int coins[] = {1, 2, 3};
    int sum = 7;

    cout << minimumNumberOfCoinsRequired(coins, 3, sum);
}