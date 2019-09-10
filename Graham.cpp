#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

struct Point
{
    int x, y;
};

Point P0;

// A utility function to find next to top in a stack
Point Next_Point (stack <Point> &S)
{
    Point p = S.top();
    S.pop();
    Point Elem = S.top();
    S.push(p);
    return Elem;
}

// A utility function to Swap_points two points
int Swap_points (Point &P1, Point &P2)
{
    Point temp = P1;
    P1 = P2;
    P2 = temp;
}

// A utility function to return square of Distance between P1 and P2
int Dist (Point P1, Point P2)
{
    return (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y);
}

int Orientation (Point P, Point Q, Point R)
{
    int val = (Q.y - P.y) * (R.x - Q.x) - (Q.x - P.x) * (R.y - Q.y);

    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// Points with respect to the first point
int Comp (const void *pct1, const void *pct2)
{
    Point *P1 = (Point *) pct1;
    Point *P2 = (Point *) pct2;

    // Find Orientation
    int o = Orientation (P0, *P1, *P2);
    if (o == 0)
        return (Dist(P0, *P2) >= Dist(P0, *P1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// Prints convex hull of a set of n points.
void Convex_Hull (Point points[], int n)
{
    // Find the bottommost point
    int ymini = points[0].y, mini = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Pick the bottom-most or chose the left most point in case of tie
        if ((y < ymini) || (ymini == y && points[i].x < points[mini].x))
            ymini = points[i].y, mini = i;
    }

    // Place the bottom-most point at first position
    Swap_points (points[0], points[mini]);

    // Sort n-1 points with Elempect to the first point.  A point P1 comes
    // before P2 in sorted ouput if P2 has larger polar angle (in
    // counterclockwise direction) than P1
    P0 = points[0];
    qsort (&points[1], n - 1, sizeof(Point), Comp);

    // Create an empty stack and push first three points to it.
    stack<Point> S;
    S.push (points[0]);
    S.push (points[1]);
    S.push (points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < n; i++)
    {
        // Keep removing top while the angle formed by points next-to-top,
        // top, and points[i] makes a non-left turn
        while (Orientation (Next_Point(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    while (!S.empty())
    {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}

// Driver program to test above functions
int main()
{
    Point points[] = { { 0, 3 }, { 1, 1 }, { 2, 2 }, { 4, 4 }, { 0, 0 },
            { 1, 2 }, { 3, 1 }, { 3, 3 } };
    int n = sizeof(points) / sizeof(points[0]);

    cout << "Graham scan: \n";

    Convex_Hull(points, n);

    return 0;
}
