#include <stdc++.h>

using namespace std;
struct point
{
    int x, y;
};
//Compare Functions needed by qsort()

int compareX(point a, point b)
{
    return (a.x < b.x);
}

int compareY(point a, point b)
{

    return (a.y < b.y);
}

int main()
{
    vector<point> points{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    vector<point> Px, Py;
    Px.resize(points.size());
    Py.resize(points.size());
    for (int i = 0; i < points.size(); i++)
    {
        Px[i].x = points[i].x;
        Px[i].y = points[i].y;
        Py[i].x = points[i].x;
        Py[i].y = points[i].y;
    }
    //Sorting points according to X
    sort(Px.begin(), Px.end(), compareX);
    sort(Py.begin(), Py.end(), compareY);

    for (int i = 0; i < Px.size(); i++)
    {
        cout << Px[i].x << " " << Py[i].y << endl;
        ;
    }
}