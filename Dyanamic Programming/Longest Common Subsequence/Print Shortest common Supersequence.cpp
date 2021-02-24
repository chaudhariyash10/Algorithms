#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];

void LCS(string a, string b)
{
    int l1 = a.size();
    int l2 = b.size();

    for (int i = 0; i < l1 + 1; i++)
        dp[i][0] = 0;
    for (int i = 0; i < l2 + 1; i++)
        dp[0][i] = 0;

    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

string shortesSupersequnce(string a, string b)
{
    LCS(a, b);
    string lcs = "";

    int i = a.size(), j = b.size();

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs = a[i - 1] + lcs;
            i--, j--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            lcs = a[i - 1] + lcs;
            i--;
        }
        else
        {
            lcs = b[j - 1] + lcs;
            j--;
        }
    }

    return lcs;
}
int main()
{
    string a = "acbcf";
    string b = "abcdaf";

    cout << shortesSupersequnce(a, b);
}