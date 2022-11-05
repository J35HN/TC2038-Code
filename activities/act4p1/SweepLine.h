#include "Event.h"
#include "Line.h"
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::set;
using std::string;
using std::to_string;
using std::vector;
using namespace std;

// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'.
bool onSegment(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y))
    return true;

  return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
  // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
  // for details of below formula.
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0)
    return 0; // collinear

  return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Line s1, Line s2) {
  Point p1 = s1.top, q1 = s1.bottom, p2 = s2.top, q2 = s2.bottom;

  // Find the four orientations needed for general and
  // special cases
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  // General case
  if (o1 != o2 && o3 != o4)
    return true;

  // Special Cases
  // p1, q1 and p2 are collinear and p2 lies on segment p1q1
  if (o1 == 0 && onSegment(p1, p2, q1))
    return true;

  // p1, q1 and q2 are collinear and q2 lies on segment p1q1
  if (o2 == 0 && onSegment(p1, q2, q1))
    return true;

  // p2, q2 and p1 are collinear and p1 lies on segment p2q2
  if (o3 == 0 && onSegment(p2, p1, q2))
    return true;

  // p2, q2 and q1 are collinear and q1 lies on segment p2q2
  if (o4 == 0 && onSegment(p2, q1, q2))
    return true;

  return false; // Doesn't fall in any of the above cases
}


int sweepLine(vector<Line> lines) {
  int result = 0;
  // 1. Event Queue
  // 2. List of lines intersecting (Status)

  unordered_map<string, int> intersections; // to note the pair for which
                                            // intersection is checked already
  // Init. our Events vector and Status list.
  vector<Event> Events;
  list<Line> Status;
  for (int i = 0; i < lines.size(); i++) {
    Events.push_back(Event(lines[i].top, true, i, false));
    Events.push_back(Event(lines[i].bottom, false, i, false));
  }
  // Sort from top to bottom all events.
  sort(Events.begin(), Events.end(),
       [](Event &e1, Event &e2) { return e1.point.y > e2.point.y; });
  // Printing points.
  /*
  for (int j = 0; j < events.size(); j++) {
    cout << endl
         << events[j].point.x << ", " << events[j].point.y << " : "
         << events[j].index + 1 << endl;
  }
  */
  // Run the Sweep Line from top to bottom
  while (!Events.empty())
  {
    // Obtain the first element of Events
    auto it = Events.begin();
    Event currentPoint = *it;
    Events.erase(it);// Erase it (current point) from Events.
    // Obtain the position in y of the Sweep Line.
    int Y = currentPoint.point.y;

    // Resolve event for three cases: Lower point, Upper point, Intersection.
    if (currentPoint.isTop == false) // Lower point.
    {
      
    } else if (currentPoint.isTop == true) // Upper point.
    {
      // Add this points line to the status. Of course, where it corresponds.
      if (Status.empty() == true)
      {
        Status.insert(Status.begin(), lines[currentPoint.index]);
      } else {
        bool flag = false;
        for (auto it = Status.begin(); it != Status.end(); it++)
        {

        }
      }
    } else if (currentPoint.isIntersection == true) // Intersection point.
    {
      // Swap the position (or index) of the lines in the current intersection.
      
    }


  }
  

  return result;
}