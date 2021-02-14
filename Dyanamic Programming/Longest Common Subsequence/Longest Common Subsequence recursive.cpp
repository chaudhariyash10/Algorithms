#include <bits/stdc++.h>
using namespace std;

int helper(string s1, string s2, int l1, int l2)
{
    if (l1 == 0 || l2 == 0)
        return 0;

    if (s1[l1 - 1] == s2[l2 - 1])
        return helper(s1, s2, l1 - 1, l2 - 1) + 1;

    else
        return max(helper(s1, s2, l1 - 1, l2), helper(s1, s2, l1, l2 - 1));
}

int longestCommonSubsequence(string s1, string s2)
{
    return helper(s1, s2, s1.size(), s2.size());
}

int main()
{
    string s1 = "abdefg";
    string s2 = "abcdghr";

    cout << longestCommonSubsequence(s1, s2);
}