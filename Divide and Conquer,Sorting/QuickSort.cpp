#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &array, int l, int r)
{
    int pivot = array[l];
    int i = l;
    for (int j = i + 1; j < r; j++)
    {
        if (array[j] < pivot)
        {
            int temp = array[i + 1];
            array[i + 1] = array[j];
            array[j] = temp;
            i++;
        }
    }
    array[l] = array[i];
    array[i] = pivot;
    return i;
}

void quickSort(vector<int> &array, int l, int r)
{
    if (l >= r)
        return;
    int pivot = partition(array, l, r);

    quickSort(array, l, pivot);
    quickSort(array, pivot + 1, r);
}

int main()
{
    vector<int> v{4, 2, 6, 3, 7, 1, 8, 10};
    quickSort(v, 0, v.size());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}