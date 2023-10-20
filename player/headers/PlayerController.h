#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Player.h"
#include <utility>
#include "../../field/headers/Field.h"

class PlayerController {
public:
    PlayerController(Player &player, Field &field);
    void move(Sides side);
    void addHealthPoints(int health_change);
    void addScore(int score_change);
    bool doesAlive();
    Point get_coordinates();
    void set_field(Field &field);

private:
    Player &player_;
    Field &field_;
};

#endif
