#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct Point {
    int x, y;
};

// A global point needed for sorting points with reference
// to the first point
Point p0;

// A utility function to find the next to top in a stack
Point nextToTop(std::stack<Point>& S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// A utility function to swap two points
void swap(Point& p1, Point& p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return the square of the distance
// between p1 and p2
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// To find the orientation of the ordered triplet (p, q, r).
// The function returns the following values:
// 0 -> p, q, and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclockwise
}

// A function used by the sort() function to sort an array
// of points with respect to the first point
bool compare(const Point& p1, const Point& p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);
    return (o == 2);
}

// Prints the convex hull of a set of n points.
void convexHull(std::vector<Point>& points, int n) {
    // Find the bottom-most point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;

        // Pick the bottom-most or choose the left most point in case of tie
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2 has
    // larger polar angle (in counterclockwise direction) than p1
    p0 = points[0];
    std::sort(points.begin() + 1, points.end(), compare);

    // Create an empty stack and push first three points to it
    std::stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < n; i++) {
        // Keep removing top while the angle formed by points next-to-top, top, and points[i] makes a non-left turn
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Now stack has the output points, print contents of stack
    std::cout << "The points in the Convex Hull are: \n";
    while (!S.empty()) {
        Point p = S.top();
        std::cout << "(" << p.x << ", " << p.y << ")\n";
        S.pop();
    }
}

int main() {
    std::vector<Point> points = {{0, 3}, {2, 3}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = points.size();
    convexHull(points, n);
    return 0;
}
