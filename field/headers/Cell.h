#ifndef CODE_CELL_H
#define CODE_CELL_H
#include <iterator>
#include <utility>

class Cell {
public:
    Cell();
    Cell(bool passable);
    Cell(const Cell& other);
    Cell& operator= (const Cell& other);
    Cell(Cell&& other);
    Cell& operator= (Cell&& other);

    void set_passablity(bool passable);

    bool isPassable() const;

private:
    bool passable_;
};


#endif //CODE_CELL_H
