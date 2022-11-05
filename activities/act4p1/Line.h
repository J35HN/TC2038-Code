#ifndef _LINE_H_
#define _LINE_H_

#include "Point.h"

class Line{
  public:
    Line(Point, Point);
    Point top;
    Point bottom;
};

Line::Line(Point _top, Point _bottom){
  top = _top;
  bottom = _bottom;
}

#endif // _LINE_H_