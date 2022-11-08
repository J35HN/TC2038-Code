#include <bits/stdc++.h>
#include <stack>

#include "Point.h"

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::vector;

/**
 * @brief Prints the elements of a stack.
 *
 * @param polygon Stack that contains the point describing a polygon.
 * Complexity: O(n).
 */
void printStack(stack<Point> polygon) {
  int polygonSize = polygon.size();
  vector<Point> polygonCounterClockwise;

  cout << "=== Convex Hull ===" << endl;

  for (int i = 0; i < polygonSize; i++) {
    polygonCounterClockwise.push_back(polygon.top());
    polygon.pop();
  }

  for (int i = polygonSize - 1; i >= 0; i--) {
    cout << polygonCounterClockwise[i].x << ", " << polygonCounterClockwise[i].y
         << endl;
  }
}

/**
 * @brief Swaps the values of two points.
 *
 * @param a Point 1.
 * @param b Point 2.
 * Complexity: O(1).
 */
void swap(Point &a, Point &b) {
  Point temp = a;
  a = b;
  b = temp;
}

/**
 * @brief Returns a reference to the top object of a stack.
 *
 * @param points A stack ofpoints.
 * @return A point object that is currently the top one of a stack.
 * Complexity: O(1).
 */
Point nextToTop(stack<Point> &points) {
  Point originalTop = points.top();
  points.pop();
  Point next = points.top();
  points.push(originalTop);
  return next;
}

/**
 * @brief Computes the angle of two points using 2nd argument arctangent.
 *
 * @param a Point from where the angle takes reference.
 * @param b Point which indicates the angle between a and b.
 * @return double Value of angle in degrees.
 * Complexity: O(1).
 */
double angleOfTwoPoints(Point a, Point b) {
  double x, y;
  double division, result;
  y = b.y - a.y;
  x = b.x - a.x;
  // Use inverse tangent for angle in radians.
  result = atan2(y, x) * (180 / 3.1415);
  return result;
}

/**
 * @brief Computes the distance of two points.
 *
 * @param p1 Point a.
 * @param p2 Point b.
 * @return double Distance of two points.
 * Complexity: O(1).
 */
double distanceOfTwoPoints(Point &p1, Point &p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/**
 * @brief Computes the orientation of two points towards a third point.
 *
 * @param a
 * @param b
 * @param c
 * @return int Orientation.
 * Complexity: O(1).
 */
int counterClockWiseDirection(Point a, Point b, Point c) {
  float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  if (area > 0)
    return 1; // Counter-clockwise.
  // if (area < 0) return -1; // Clockwise
  return 0; // Collinear
}

/**
 * @brief Algorith that finds the convex hull of a finite set of points.
 *
 * @param points Vector contaning the points of a plane.
 * @return vector<Point>
 * Complexity: O(n log n).
 */
void grahamScan(vector<Point> points) {
  // Pick the bottom most, left most point.
  int lowest = 0;
  for (int i = 1; i < points.size(); i++) {
    if (points[i].y < points[lowest].y) {
      lowest = i;
    } else if (points[i].y == points[lowest].y) {
      if (points[i].x <= points[lowest].x) {
        lowest = i;
      }
    }
  }
  // Swap values with the first element of the vector with the lowest point.
  swap(points[lowest], points[0]);

  // Sort by angle in respect to lowest point.
  // First, compute the angle and distance in respect to lowest point, then
  // sort.
  for (int i = 0; i < points.size(); i++) {
    points[i].angle = angleOfTwoPoints(points[0], points[i]);
    points[i].distance = distanceOfTwoPoints(points[0], points[i]);
  }
  // Sort
  sort(points.begin(), points.end(), [](Point &p1, Point &p2) {
    if (p1.angle == p2.angle) {
      return p1.distance < p2.distance;
    }
    return p1.angle < p2.angle;
  });
  // Push the three first points.
  stack<Point> polygon;
  polygon.push(points[0]);
  polygon.push(points[1]);
  polygon.push(points[2]);
  // Pop or push a point depending in its direction.
  for (int i = 3; i < points.size(); i++) {
    while (polygon.size() > 1 &&
           counterClockWiseDirection(polygon.top(), nextToTop(polygon),
                                     points[i])) {
      polygon.pop();
    }
    polygon.push(points[i]);
  }

  if (polygon.size() < 3) {
    cout << "=== This set of points does not have a convex hull ===" << endl;
  } else {
    printStack(polygon);
  }
}