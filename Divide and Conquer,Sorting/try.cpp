#include<stdc++.h>

using namespace std;

struct point{
    int x, y;
};

int compareX(const void* point1, const void * point2)
{
    point *p1 = (point *)point1, *p2 = (point *)point2;
    return (p1->x - p2->x);
}

int compareY(const void *point1, const void *point2)
{
    point *p1 = (point *)point1, *p2 = (point *)point2;
    return (p1->y - p2->y);
}

float dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float BruteForce(point array[], int n)
{
    float min = FLT_MAX;
    for(int i )
}

int main()
{

}