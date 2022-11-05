#ifndef _EVENT_H_
#define _EVENT_H_

#include "Point.h"

class Event {
public:
  Point point;
  bool isTop;
  bool isIntersection;
  int index;
  Event(Point, bool, int, bool);
  bool operator<(const Event &) const;
};

Event::Event(Point _point, bool _isTop, int _index, bool _isIntersection) {
  point = _point;
  isTop = _isTop;
  index = _index;
  isIntersection = _isIntersection;

}

bool Event::operator<(const Event &event) const {
  if (point.y == event.point.y) {
    return point.x < event.point.x;
  }
  return point.y < event.point.y;
}


#endif // _EVENT_H_