#ifndef PLAYER_CONTROLLER_CPP
#define PLAYER_CONTROLLER_CPP

#include "../headers/PlayerController.h"

PlayerController::PlayerController(Player *player) {
    player_ = player;
    x_coordinate_ = 0;
    y_coordinate_ = 0;
}

int PlayerController::Move(Sides side, int step_count) {
    if(step_count <= 0)
        return -1;

    if(side == Sides::UP){
        y_coordinate_ -= step_count;
    }else if(side == Sides::DOWN){
        y_coordinate_ += step_count;
    }else if(side == Sides::LEFT){
        x_coordinate_ -= step_count;
    }else{
        x_coordinate_ += step_count;
    }
    return 0;
}

std::pair<int, int> PlayerController::get_both_coordinates() {
    return std::make_pair(x_coordinate_, y_coordinate_);
}

int PlayerController::x_coordinate() {
    return x_coordinate_;
}

int PlayerController::y_coordinate() {
    return y_coordinate_;
}

#endif