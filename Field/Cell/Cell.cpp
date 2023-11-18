#ifndef CELL_CPP
#define CELL_CPP

#include "Cell.h"

Cell::Cell() : Cell(true) {}

Cell::Cell(bool passable) : Cell(passable, nullptr){}

Cell::Cell(bool passable, EventInterface *event) : passable_(passable), event_(event) {}

Cell::Cell(const Cell& other) : Cell() {
    swap(other);
}

void Cell::swap(Cell &&other) {
    removeEvent();
    std::swap(passable_, other.passable_);
    std::swap(event_, other.event_);
}

void Cell::swap(const Cell &other) {
    passable_ = other.passable_;
    removeEvent();
    event_ = (other.event_== nullptr) ? nullptr : other.event_->copy();
}

Cell& Cell::operator= (const Cell& other) {
    Cell temp(other);
    swap(temp);
    return *this;
}

Cell::Cell(Cell&& other) : Cell() {
    swap(other);
}

Cell& Cell::operator= (Cell&& other) {
    if(this != &other) {
        swap(other);
    }
    return *this;
}

void Cell::set_passablity(bool passable) {
    passable_ = passable;
}

bool Cell::isPassable() const {
    return passable_;
}

void Cell::executeEvent(PlayerController &controller) {
    if(event_ != nullptr) {
        event_ =  event_->execute(controller);
    }
}

bool Cell::isEvent() const {
    return event_ != nullptr;
}

void Cell::removeEvent() {
    if(event_ != nullptr) {
        delete event_;
        event_ = nullptr;
    }
}

void Cell::addEvent(EventInterface *event) {
    removeEvent();
    event_ = event;
}

Cell::~Cell() {
    removeEvent();
}

EventInterface *Cell::event() {
    return event_;
}

#endif