#ifndef CODE_CELL_H
#define CODE_CELL_H
#include <iterator>
#include <utility>
#include "../../event/interface/EventInterface.h"

class Cell {
public:
    Cell();
    Cell(bool passable);
    Cell(bool passable, EventInterface *event);
    Cell(const Cell& other);
    Cell& operator= (const Cell& other);
    Cell(Cell&& other);
    Cell& operator= (Cell&& other);

    void set_passablity(bool passable);

    bool isPassable() const;
    bool isEvent() const;

    void execute_event(PlayerController &controller);
    void addEvent(EventInterface *event);

private:
    void swap(Cell &&other);
    void swap(const Cell& other);
    void remove_event();

    bool passable_;
    EventInterface *event_;
};


#endif //CODE_CELL_H
