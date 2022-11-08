#include <bits/stdc++.h>

#include "Point.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
  result = atan2(y, x) * (180/3.1415);
  return result;
}

/**
 * @brief Computes the distance of two points.
 * 
 * @param p1 Point a.
 * @param p2 Point b.
 * @return double 
 * Complexity: O(1).
 */
double distanceOfTwoPoints(Point &p1, Point &p2){
  return sqrt(pow(p2.x-p1.x, 2) + pow(p2.y-p1.y, 2));
}

/**
 * @brief Algorith that finds the convex hull of a finite set of points.
 * 
 * @param points Vector contaning the points of a plane.
 * @return vector<Point>
 * Complexity: O(n log n). 
 */
vector<Point> grahamScan(vector<Point> points) {
  // Pick the bottom most, left most point.
  Point lowest = points[0];
  for (int i = 1; i < points.size(); i++) {
    if (points[i].y < lowest.y) {
      lowest = points[i];
    } else if (points[i].y == lowest.y) {
      if (points[i].x <= lowest.x) {
        lowest = points[i];
      }
    }
  }
  // Swap values with the first element of the vector with the lowest point.
  swap(lowest, points[0]);
  
  // Sort by angle in respect to lowest point.
  // First, compute the angle and distance in respect to lowest point, then sort.
  for (int i = 0; i < points.size(); i++) {
    points[i].angle = angleOfTwoPoints(lowest, points[i]);
    points[i].distance = distanceOfTwoPoints(lowest, points[i]);
  }
  sort(points.begin(), points.end(), [](Point &p1, Point &p2){
    if(p1.angle == p2.angle){
      return p1.distance > p2.distance;
    }
    return p1.angle < p2.angle;
  });

  for (int i = 0; i < points.size(); i++) {
    cout << i << ": " << points[i].x << ", " << points[i].y << "  Angle: " << points[i].angle << endl;
  }
  
  return points;
}