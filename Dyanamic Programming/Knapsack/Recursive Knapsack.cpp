#include <bits/stdc++.h>

using namespace std;

int knapsack(int val[], int wt[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapsack(val, wt, W, n - 1);

    else
        return max(val[n - 1] + knapsack(val, wt, W - wt[n - 1], n - 1), knapsack(val, wt, W, n - 1));
}

int main()
{
    int val[] = {1, 2, 4, 5, 4, 8};
    int wt[] = {1, 2, 3, 5, 6, 7}; 
    
    int W = 6;
    
    cout << knapsack(val, wt, W, 6);
}
