//
// Created by Leha Kolkovich on 10.10.2023.
//

#include "../headers/Cell.h"

Cell::Cell() : type_(CellType::PASSABLE){}

Cell::Cell(CellType type) : type_(type){}

Cell::Cell(const Cell& other) : type_(other.type_) {}

Cell& Cell::operator = (const Cell& other) {
    Cell temp(other);
    std::swap(type_, temp.type_);
    return *this;
}

Cell::Cell(Cell&& other) : type_(other.type_) {}

Cell& Cell::operator = (Cell&& other) {
    if(this != &other) {
        std::swap(type_, other.type_);
    }
    return *this;
}

void Cell::set_type(CellType type) {
    type_ = type;
}



bool Cell::isStart() const {
    return type_ == CellType::START;
}

bool Cell::isFinish() const {
    return type_ == CellType::FINISH;
}

bool Cell::isPassable() const {
    return type_ != CellType::UNPASSABLE;
}
