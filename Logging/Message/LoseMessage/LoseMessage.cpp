#include "LoseMessage.h"


LoseMessage::LoseMessage(Point lose_coordinates) : lose_coordinates_(lose_coordinates) {}


void LoseMessage::toPrint(std::ostream &out_str) const {
    out_str << "Player lose on cell: x=" << lose_coordinates_.x << " | y=" << lose_coordinates_.y << '\n';
}