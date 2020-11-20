#include <stdc++.h>

using namespace std;

//Naive aprroach:

int **initialiseMatrix(int n)
{
    int **c = new int *[n];

    for (int i = 0; i < n; i++)
        c[i] = new int[n];

    return c;
}

void setToZero(int **c, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            c[i][j] = 0;
    }
}

//Naive Method
int **naiveMultiply(int **A, int **B, int n)
{
    int **c = initialiseMatrix(n);
    setToZero(c, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                c[i][j] += A[i][k] * B[k][j];
        }
    }

    return c;
}

void print(int **c, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
    }
}

int **add(int **a, int **b, int n)
{
    int **c = initialiseMatrix(n);

    setToZero(c, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return c;
}

int **subtract(int **a, int **b, int n)
{
    int **c = initialiseMatrix(n);

    setToZero(c, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    return c;
}

//Strassen's Algorithm:
// Trivial Algorithm takes O(n3) time for matrix multiplication
// We can do better by divide and conquer
// [a b] [e f]   = [ae+bg  af+bh]   = [c1 c2]
// [c d] [g h]   = [ce+dg  cf+dh]   = [c3 c4]

//for strassen's algorithm we have to calculate the resultant matrix by 7 recursive calls instead of 8.
// We will Calculate following:
//  p1 = (a + d).(e + h)    = p5
//  p2 = (c + d). e         = p3
//  p3 = a . (f - h)        = p1
//  p4 = d . (g - e)        = p4
//  p5 = (a + b).h          = p2
//  p6 = (c - a).(e + f)    = p7
//  p7 = (b - d).(g + h)    = p6

//From this we can calculate Matrix:
// c1 = p1 + p4 -p5 + p7
// c2 = p3 + p5
// c3 = p2 + p4
// c4 = p1 + p3 - p2 + p6

int **strassensMultiply(int **A, int **B, int n)
{
    int **C = initialiseMatrix(n);
    if (n == 1)
    {

        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    //Creating submatrices
    int k = n / 2;

    int **a = initialiseMatrix(k);
    int **b = initialiseMatrix(k);
    int **c = initialiseMatrix(k);
    int **d = initialiseMatrix(k);
    int **e = initialiseMatrix(k);
    int **f = initialiseMatrix(k);
    int **g = initialiseMatrix(k);
    int **h = initialiseMatrix(k);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            a[i][j] = A[i][j];
            b[i][j] = A[i][j+k];
            c[i][j] = A[i + k][j];
            d[i][j] = A[k + i][k + j];
            e[i][j] = B[i][j];
            f[i][j] = B[i][j + k];
            g[i][j] = B[i + k][j];
            h[i][j] = B[k + i][k + j];
        }
    }

    int **p1 = strassensMultiply(add(a, d, k), add(e, h, k), k);
    int **p2 = strassensMultiply(add(c, d, k), e, k);
    int **p3 = strassensMultiply(a, subtract(f, h, k), k);
    int **p4 = strassensMultiply(d, subtract(g, e, k), k);
    int **p5 = strassensMultiply(add(a, b, k), h, k);
    int **p6 = strassensMultiply(subtract(c, a, k), add(e, f, k), k);
    int **p7 = strassensMultiply(subtract(b, d, k), add(g, h, k), k);

    // c1 = p1 + p4 -p5 + p7
    // c2 = p3 + p5
    // c3 = p2 + p4
    // c4 = p1 + p3 - p2 + p6
    int **c1 = add(subtract(add(p1, p4, k), p5, k), p7, k);
    int **c2 = add(p3, p5, k);
    int **c3 = add(p2, p4, k);
    int **c4 = add(subtract(add(p1, p3, k), p2, k), p6, k);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = c1[i][j];
            C[i][j + k] = c2[i][j];
            C[i + k][j] = c3[i][j];
            C[i + k][j + k] = c4[i][j];
        }
    }

    return C;
}
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int **A, **B;
    A = initialiseMatrix(n);
    B = initialiseMatrix(n);
    cout << "\n1st Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "\n2nd Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
        }
    }

    int **c = initialiseMatrix(n);

    c = strassensMultiply(A, B, n);
    print(c, n);
}