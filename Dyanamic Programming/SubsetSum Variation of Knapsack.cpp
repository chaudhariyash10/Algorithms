#include <bits/stdc++.h>
using namespace std;

//Recursive ==========================================================================================================
//=====================================================================================================================
// bool isSubsetSum(int arr[], int sum, int n)
// {
//     if (sum == 0)
//         return true;
//     if (n == 0)
//         return false;

//     if (arr[n - 1] > sum)
//         return isSubsetSum(arr, sum, n - 1);

//     else
//         return (isSubsetSum(arr, sum - arr[n - 1], n - 1) || isSubsetSum(arr, sum, n - 1));
// }

//Memoised==========================================================================================================
//=====================================================================================================================

//Constraints   n < 1001, sum< 100000
// bool dp[1001][100001];

// bool isSubsetSum(int arr[], int sum, int n)
// {
//     if (sum == 0)
//         return true;

//     if (n == 0 || sum < 0)
//         return false;

//     if (dp[n - 1][sum])
//         return true;

//     if (arr[n - 1] > sum)
//         return dp[n - 1][sum] = isSubsetSum(arr, sum, n - 1);
//     else
//         return dp[n - 1][sum] = (isSubsetSum(arr, sum - arr[n - 1], n - 1) || isSubsetSum(arr, sum, n - 1));
// }

bool dp[1001][100001];

void isSubsetSum(int arr[], int sum, int n)
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
}

int main()
{
    // for memoised approach
    int n = 6;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    for (int i = 1; i < 100001; i++)
        dp[0][i] = false;

    int arr[] = {1, 3, 5, 6, 8, 10};
    int sum = 12;

    isSubsetSum(arr, sum, 6);
    cout << dp[6][sum];
}