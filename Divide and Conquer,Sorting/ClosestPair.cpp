//O(n(logn)^2)

#include <bits/stdc++.h>

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

// Calculating distance betn two points

float distance(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

//BruteForce to find solution

float BruteForce(vector<point> points, int l, int r)
{
    float min = FLT_MAX;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j < r; j++)
        {
            if (distance(points[i], points[j]) < min)
                min = distance(points[i], points[j]);
        }
    }

    return min;
}

//Utility to find Lesser of two floats

float min(float a, float b)
{
    return (a < b) ? a : b;
}

//Strip close Utility to find required points in strip

// A utility function to find the
// distance beween the closest points of
// strip of given size. All points in
// strip[] are sorted accordint to
// y coordinate. They all have an upper
// bound on minimum distance as d.
// Note that this method seems to be
// a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(vector<point> &strip, float mini)
{
    //Sort by Y co-ordinate
    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = 0; j < strip.size() && abs(strip[i].y - strip[j].y) < mini; j++)
        {
            if (distance(strip[i], strip[j]) < mini)
                mini = distance(strip[i], strip[j]);
        }
    }

    return mini;
}

//Closest util is recursive method to find smallest distance

float closestUtil(vector<point> &points, int l, int r)
{
    //Use BruteForce if input is less than 3

    if ((r - l) < 3)
        return BruteForce(points, l, r);

    //getting middle point
    int mid = (r + l) / 2;
    point midPoint = points[mid];

    // Consider the vertical line passing
    // through the middle point calculate
    // the smallest distance dl on left
    // of middle point and dr on right side

    float dl = closestUtil(points, l, mid);
    float dr = closestUtil(points, mid + 1, r);

    float mini = min(dl, dr);

    // Build an array strip[] that contains
    // points close (closer than d)
    // to the line passing through the middle point
    vector<point> strip;
    int j = 0;
    for (int i = l; i < r; i++)
    {
        if (abs(points[i].x - midPoint.x) < mini)
        {
            strip.resize(j);
            strip[j] = points[i];
            j++;
        }
    }

    //Find the required points in strip if points are splitted in different sections made by midPoint
    return min(mini, stripClosest(strip, mini));
}

float closest(vector<point> &points)
{
    //Making copies of points array to sort by X and Y,
    //in order to get Px and Py

    //Sorting According to X....
    sort(points.begin(), points.end(), compareX);

    return closestUtil(points, 0, points.size());
}

int main()
{
    vector<point> points{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    cout << "Smallest Distance is: " << closest(points);
}