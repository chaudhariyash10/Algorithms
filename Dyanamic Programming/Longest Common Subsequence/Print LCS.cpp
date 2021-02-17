#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int longestCommonSubsequence(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[l1][l2];
}

string printLCS(string s1, string s2)
{
    longestCommonSubsequence(s1, s2);
    // for (int i = 0; i < s1.size() + 1; i++)
    // {
    //     for (int j = 0; j < s2.size() + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int i = s1.size();
    int j = s2.size();

    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--, j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;

        // cout << i << " " << j << s1[i] << " " << s2[j] << endl;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1 = "abde";
    string s2 = "abcd";

    cout << printLCS(s1, s2);
    // cout << longestCommonSubsequence(s1, s2);
}