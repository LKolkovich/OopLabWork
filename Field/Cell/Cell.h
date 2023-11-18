#ifndef CODE_CELL_H
#define CODE_CELL_H
#include <iterator>
#include <utility>
#include "../../Event/EventInterface/EventInterface.h"

class Cell {
public:
    Cell();
    ~Cell();
    Cell(bool passable);
    Cell(bool passable, EventInterface *event);
    Cell(const Cell& other);
    Cell& operator= (const Cell& other);
    Cell(Cell&& other);
    Cell& operator= (Cell&& other);

    void set_passablity(bool passable);

    bool isPassable() const;
    bool isEvent() const;
    EventInterface* event();

    void executeEvent(PlayerController &controller);
    void addEvent(EventInterface *event);

private:
    void swap(Cell &&other);
    void swap(const Cell& other);
    void removeEvent();

    bool passable_;
    EventInterface *event_;

};


#endif //CODE_CELL_H
