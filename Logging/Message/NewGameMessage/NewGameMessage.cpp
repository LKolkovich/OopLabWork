#include "NewGameMessage.h"

NewGameMessage::NewGameMessage(Point field_size, Point start_coordinates) : field_size_(field_size), start_coordinates_(start_coordinates) {}

void NewGameMessage::toPrint(std::ostream &out_str) const {
    out_str << "New game start: field_size: x=" << field_size_.x << " | y=" << field_size_.y <<
                    " || start: x=" << start_coordinates_.x << " | y=" << start_coordinates_.y << '\n';
}