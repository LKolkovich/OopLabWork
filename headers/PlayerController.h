#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Player.h"
#include "Sides.h"
#include <utility>

class PlayerController{
public:
    PlayerController(Player *player);
    int Move(Sides side, int step_count);
    int x_coordinate();
    int y_coordinate();
    std::pair<int, int> get_both_coordinates();


private:
    int x_coordinate_;
    int y_coordinate_;
    Player *player_;
};

#endif