#include <bits/stdc++.h>

using namespace std;

//This problem reduces to finding number of subsets with sum = (diff + sum(arr)) / 2;

int dp[21][1001];

int countSubsetSum(int arr[], int sum, int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > sum)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int countNumberOfSubsetSumsWithGivenDiff(int arr[], int n, int diff)
{
    int arrSum = 0;

    for (int i = 0; i < n; i++)
        arrSum += arr[i];
    int sumOfSubset = (diff + arrSum) / 2;

    return countSubsetSum(arr, n, sumOfSubset);
}

int main()
{
    for (int i = 0; i < 21; i++)
        dp[i][0] = 1;
    for (int i = 1; i < 1001; i++)
        dp[0][i] = 0;

    int arr[] = {1, 1, 2, 3};
    int diff = 1;

    cout << countNumberOfSubsetSumsWithGivenDiff(arr, 4, diff);
}