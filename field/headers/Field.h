//
// Created by Leha Kolkovich on 10.10.2023.
//

#ifndef CODE_FIELD_H
#define CODE_FIELD_H

#define MAX_SIZE 100
#define MIN_SIZE 5

#include "Cell.h"
#include "Point.h"

class Field {
public:
    Field();
    ~Field();
    Field(const Point& size);
    Field(int x, int y);

    Field(const Field& other);
    Field(Field&& other);
    Field& operator = (const Field& other);
    Field& operator = (Field&& other);

    void createField();
    void clearField();

    Cell& getCell(const Point& coordinates);
    Cell& getCell(Point&& coordinates);
    void setCell(const Point& coordinates, const Cell& cell);
    void setCell(const Point& coordinates, Cell&& cell);
    bool doesContainsPoint(const Point& coordinates) const;
    bool isPassable(const Point& coordinates);

    Point& size();
    Point& finish();
    Point& start();

    void set_start(const Point& coordinates);
    void set_finish(const Point& coordinates);
    void createWall(const Point& coordinates);
    void makePassable(const Point& coordinates);

private:
    Point size_;
    Cell** field_;
    Point start_;
    Point finish_;
};


#endif //CODE_FIELD_H
