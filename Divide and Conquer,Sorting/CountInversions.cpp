
//799 0232 6100
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int l, int mid, int r)
{

    if (l >= r)
        return 0;
    vector<int> b;
    vector<int> c;

    for (int i = l; i <= mid; i++)
    {
        b.push_back(a[i]);
    }
    for (int i = mid + 1; i <= r; i++)
    {
        c.push_back(a[i]);
    }

    int i = 0, j = 0, k = l, count = 0;

    while (i < b.size() && j < c.size())
    {
        if (b[i] < c[j])
        {
            a[k] = b[i];
            k++;
            i++;
        }
        else
        {
            a[k] = c[j];
            count += mid - l - i + 1;
            k++;
            j++;
        }
    }

    while (i < b.size())
    {
        a[k] = b[i];
        k++;
        i++;
    }

    while (j < c.size())
    {
        a[k] = c[j];
        k++;
        j++;
    }
    return count;
}

int mergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return 0;

    int count = 0;
    int mid = (r + l) / 2;

    count += mergeSort(a, l, mid);

    count += mergeSort(a, mid + 1, r);

    count += merge(a, l, mid, r);

    return count;
}

// Driver code
int main()
{
    vector<int> v{6, 5, 4, 3, 2, 1};

    int ans = mergeSort(v, 0, v.size() - 1);
    cout << " Number of inversions are " << ans;
}