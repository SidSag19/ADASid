#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

vector<Point> hull;

int getDistance(Point pt1, Point pt2, Point pt3) {
    return (pt1.x * (pt2.y - pt3.y)) - (pt2.x * (pt1.y - pt3.y)) + (pt3.x * (pt1.y - pt2.y));
}

void divideAndConquer(Point p1, Point p2, const vector<Point>& points) {
    if (points.empty()) return;

    Point farthestPoint = {-1, -1};
    int maxDist = 0;
    bool found = false;

    for (Point p : points) {
        int dist = getDistance(p1, p2, p);
        if (dist > maxDist) {
            maxDist = dist;
            farthestPoint = p;
            found = true;
        }
    }

    if (!found) return; 

    hull.push_back(farthestPoint);

    vector<Point> leftEdgeList;
    vector<Point> rightEdgeList;

    for (Point p : points) {
        if (p.x == farthestPoint.x && p.y == farthestPoint.y) continue;

        if (getDistance(p1, farthestPoint, p) > 0) {
            leftEdgeList.push_back(p);
        }
        if (getDistance(farthestPoint, p2, p) > 0) {
            rightEdgeList.push_back(p);
        }
    }

    divideAndConquer(p1, farthestPoint, leftEdgeList);
    divideAndConquer(farthestPoint, p2, rightEdgeList);
}

void solveQuickHull(const vector<Point>& points) {
    hull.clear(); 
    if (points.size() < 3) return; 

    Point p1 = points[0], p2 = points[0]; 
    for (Point p : points) {
        if (p.x > p1.x) p1 = p; 
        if (p.x < p2.x) p2 = p; 
    }

    hull.push_back(p1);
    hull.push_back(p2);

    vector<Point> leftList;
    vector<Point> rightList;

    for (Point p : points) {
        if (getDistance(p1, p2, p) > 0) leftList.push_back(p);
        if (getDistance(p2, p1, p) > 0) rightList.push_back(p);
    }

    divideAndConquer(p1, p2, leftList);
    divideAndConquer(p2, p1, rightList);
}

int main() {
    vector<Point> points = {{1,1}, {1,3}, {-1,2}, {3,1}, {0,0}, {-21,21}};

    solveQuickHull(points);

    cout << "Points forming the Convex Hull are: ";
    for (Point p : hull) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << "\n";

    return 0;
}