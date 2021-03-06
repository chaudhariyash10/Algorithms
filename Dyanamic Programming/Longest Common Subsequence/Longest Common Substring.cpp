#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int longestCommonSubsequence(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();
    int ans = 0;
    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main()
{
    string s1 = "abdefg";
    string s2 = "abcdghr";

    cout << longestCommonSubsequence(s1, s2);
}