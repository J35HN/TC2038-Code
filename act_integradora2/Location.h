#ifndef _LOCATION_H_
#define _LOCATION_H_
class Location {
    public:
        Location();
        Location(int, int);
        int x;
        int y;
};

Location::Location()
{
    x = 0;
    y = 0;
}

Location::Location(int _x, int _y)
{
    x = _x;
    y = _y;
}

#endif // _LOCATION_H_