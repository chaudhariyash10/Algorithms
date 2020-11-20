#include <stdc++.h>

using namespace std;

//Brute Force....
//Time: O(n2);
string multiply(string a, string b)
{
    vector<int> res(a.size() + b.size(), 0);
    string ans;
    int curPos = res.size() -1;
    unsigned long int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int a_i = a[i] - '0';
        unsigned long int temp = 0;

        for (int j = 0; j < b.size(); j++)
        {
            int b_j = b[j] - '0';

            temp = temp * 10 + a_i * b_j;
        }
        temp += carry;
        res[curPos] = temp % 10;
        curPos--;

        carry = temp / 10;
    }

    while(carry)
    {
        res[curPos] = carry % 10;
        curPos--;
        carry = carry / 10;
    }
    int flag = 0;
    for (int i = 0; i < res.size(); i++)
    {
            if(res[i])
                flag = 1;
        if(flag) 
        ans = ans + to_string(res[i]);
    }

    return ans;
}


int main()
{
    string a, b;
    a = "4944592";
    b = "7627";

    string c = multiply(a, b);

    cout << c;
}