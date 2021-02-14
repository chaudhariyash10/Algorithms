#include <bits/stdc++.h>
using namespace std;

bool dp[1001][100001];

bool isSubsetSum(int arr[], int sum, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i] <= sum)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

bool equalSumPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 == 1)
        return false;

    return isSubsetSum(arr, sum / 2, n);
}

int main()
{
    int n = 4;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    int arr[] = {1, 5, 5, 11};
    cout << equalSumPartition(arr, n);
}