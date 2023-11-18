#ifndef CODE_POINT_CPP
#define CODE_POINT_CPP

#include "Point.h"

Point Point::operator+(const Point& other) const {
    return Point{x + other.x, y + other.y};
}

Point Point::operator-(const Point& other) const {
    return Point{x - other.x, y - other.y};
}

Point& Point::operator+=(const Point& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Point& Point::operator-=(const Point& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

bool Point::operator==(const Point& other) const {
    return (x == other.x) && (y == other.y);
}

bool Point::operator!=(const Point& other) const {
    return !(operator==(other));
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << '(' << point.x << ", " << point.y << ')';
}

#endif //CODE_POINT_CPP
