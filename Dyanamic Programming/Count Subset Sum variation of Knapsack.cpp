#include <bits/stdc++.h>
using namespace std;

// int countSubsetSum(int arr[], int sum, int n)
// {
//     if (sum == 0)
//         return 1;
//     if (n == 0)
//         return 0;

//     if (arr[n - 1] <= sum)
//     {
//         return (countSubsetSum(arr, sum, n - 1) + countSubsetSum(arr, sum - arr[n - 1], n - 1));
//     }

//     else
//     {
//         return (countSubsetSum(arr, sum, n - 1));
//     }
// }

//==================================================================================================================================================================================================================================================
// int dp[1000][100000];

// int countSubsetSum(int arr[], int sum, int n)
// {
//     if (sum == 0)
//         return 1;
//     if (n == 0)
//         return 0;

//     if (dp[n][sum])
//         return dp[n][sum];

//     if (arr[n - 1] <= sum)
//     {
//         return dp[n][sum] = (countSubsetSum(arr, sum, n - 1) + countSubsetSum(arr, sum - arr[n - 1], n - 1));
//     }

//     else
//     {
//         return dp[n][sum] = (countSubsetSum(arr, sum, n - 1));
//     }
// }

int dp[1000][100000];

int countSubsetSum(int arr[], int sum, int n)
{
    for (int i = 1; i < n +1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if(arr[i - 1] > sum)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < 100000; i++)
        dp[0][i] = 0;

    int n = 8;
    int sum = 10;

    int arr[] = {1, 2, 3, 5, 8, 9, 10, 11};

    cout << countSubsetSum(arr, sum, n);
}