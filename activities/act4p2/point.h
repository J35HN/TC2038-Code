#ifndef _POINT_H_
#define _POINT_H_

class Point {
public:
  Point();
  Point(int, int);
  int x;
  int y;
  double angle;
  double distance;
};

Point::Point() {
  x = 0;
  y = 0;
  angle = 0;
  distance = 0;
}

Point::Point(int _x, int _y) {
  x = _x;
  y = _y;
  angle = 0;
  distance = 0;
}

#endif // _POINT_H_