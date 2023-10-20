#include "../headers/Cell.h"

Cell::Cell() : passable_(true) {}

Cell::Cell(bool passable) : passable_(passable){}

Cell::Cell(const Cell& other) : passable_(other.passable_) {}

Cell& Cell::operator= (const Cell& other) {
    Cell temp(other);
    std::swap(passable_, temp.passable_);
    return *this;
}

Cell::Cell(Cell&& other) : passable_(other.passable_) {}

Cell& Cell::operator= (Cell&& other) {
    if(this != &other) {
        std::swap(passable_, other.passable_);
    }
    return *this;
}

void Cell::set_passablity(bool passable) {
    passable_ = passable;
}

bool Cell::isPassable() const {
    return passable_;
}
