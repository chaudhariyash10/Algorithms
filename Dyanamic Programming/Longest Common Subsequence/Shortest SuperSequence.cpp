#include <bits/stdc++.h>

using namespace std;

int LCS(string a, string b)
{
    int l1 = a.size();
    int l2 = b.size();
    int dp[l1 + 1][l2 + 1];

    for (int i = 0; i < l1 + 1; i++)
        dp[0][i] = 0;
    for (int i = 0; i < l2 + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[l1][l2];
}

int shortestSupersequence(string a, string b)
{
    int lengthOfLCS = LCS(a, b);

    return a.size() + b.size() - lengthOfLCS;
}

int main()
{
    string a = "aggtab";
    string b = "gxtxayb";

    cout << shortestSupersequence(a, b);
}