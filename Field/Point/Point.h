#ifndef CODE_POINT_H
#define CODE_POINT_H
#include <iostream>

struct Point {
    int x;
    int y;

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point& operator+=(const Point& other);
    Point& operator-=(const Point& other);
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};



//перегружать вывод можно, но используя friend


#endif //CODE_POINT_H
