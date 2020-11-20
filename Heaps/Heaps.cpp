#include <bits/stdc++.h>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap
{
    int *array;
    //Maximum size of Heap
    int capacity;
    int size;

public:
    MinHeap(int capa);
    void print()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
    }
    //to heapify subtree with root as given index
    void MinHeapify(int);

    //Returning index of parent or child of given index::

    int parent(int i) { return (i - 1) / 2; }

    int leftChild(int i) { return 2 * i + 1; };

    int rightChild(int i) { return 2 * i + 2; };

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin() { return array[0]; }
    //Delete key stored at index i
    void deleteKey(int i);
    //Insert new key K
    void insertKey(int k);
};

MinHeap::MinHeap(int capa)
{
    size = 0;
    capacity = capa;
    array = new int[capa];
}

void MinHeap::insertKey(int k)
{
    if (capacity == size)
    {
        cout << "\nOverflow!!!Cannot insert Key";
        return;
    }

    size = size + 1;
    int i = size - 1;
    array[i] = k;

    while (i != 0 && array[parent(i)] > array[i])
    {
        swap(array[parent(i)], array[i]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int newVal)
{
    array[i] = newVal;

    while (i > 0 && array[parent(i)] > array[i])
    {
        swap(array[parent(i)], array[i]);
        i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if (size <= 0)
    {
        return INT_MAX;
    }
    if (size == 1)
    {
        size--;
        return array[0];
    }

    int root = array[0];
    array[0] = array[size - 1];
    size--;
    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;

    if (l < size && array[l] < array[i])
        smallest = l;
    if (r < size && array[r] < array[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(array[i], array[smallest]);

        MinHeapify(smallest);
    }
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << endl;
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}