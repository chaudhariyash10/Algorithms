#include <stdc++.h>

using namespace std;

//Only for positive Integers....

int getLength(int X)
{
    if (X < 10)
    {
        return 1;
    }
    int l = 0;

    while (X > 0)
    {
        l++;
        X = X / 10;
    }

    return l;
}

int multiply(int x, int y)
{
    if (x < 10 && y < 10)
    {
        return x * y;
    }

    int size = max(getLength(x), getLength(y));

    int n = size / 2;

    int p = pow(10, n);

    int a = x / p;
    int b = x % p;
    int c = y / p;
    int d = y % p;

    int ac = multiply(a, c);
    int bd = multiply(b, d);

    int ad_bc = multiply((a + b), (c + d)) - ac - bd;

    return (pow(10, 2 * n) * ac + pow(10, n) * ad_bc + bd);
}

int main()
{
    int a = 890;
    int b = 567;

    cout << multiply(a, b);
}