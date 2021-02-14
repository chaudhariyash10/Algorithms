#include <bits/stdc++.h>

using namespace std;

int maxNumberOfWaystoGetSum(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int i = 1; i < sum + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int coins[] = {1, 2, 3};
    int sum = 5;

    cout << maxNumberOfWaystoGetSum(coins, 3, 5);
}