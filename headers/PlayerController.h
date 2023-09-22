#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Player.h"
#include "Sides.h"
#include <utility>

class PlayerController {
public:
    PlayerController(Player *player);
    int move(Sides side);
    int add_health_points(int health_change);
    void add_score(int score_change);
    std::pair<int, int> get_coordinates();

private:
    Player *player_;
};

#endif