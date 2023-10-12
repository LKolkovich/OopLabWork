//
// Created by Leha Kolkovich on 10.10.2023.
//

#ifndef CODE_CELL_H
#define CODE_CELL_H
#include "CellType.h"
#include <iterator>
#include <utility>

class Cell {
public:
    Cell();
    Cell(CellType type);
    Cell(const Cell& other);
    Cell& operator= (const Cell& other);
    Cell(Cell&& other);
    Cell& operator= (Cell&& other);

    void set_type(CellType type);

    bool isStart() const;
    bool isFinish() const;
    bool isPassable() const;

private:
    CellType type_;
};


#endif //CODE_CELL_H
