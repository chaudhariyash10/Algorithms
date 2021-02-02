#include <bits/stdc++.h>
using namespace std;

bool dp[21][1001];

void isSubsetSum(int arr[], int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    for (int i = 1; i < sum + 1; i++)
        dp[0][i] = false;

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
}

int minimumSubsetDifference(int arr[], int n)
{
    int Range = 0;
    for (int i = 0; i < n; i++)
        Range += arr[i];
    isSubsetSum(arr, Range, n);

    vector<int> sums;
    int mini = INT_MAX;
    for (int i = 0; i <= Range / 2; i++)
        if (dp[n][i])
            mini = min(mini, Range - 2 * i);
    return mini;
}

int main()
{
    int arr[] = {1, 2, 7};

    cout << minimumSubsetDifference(arr, 3);
}