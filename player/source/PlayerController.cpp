#ifndef PLAYER_CONTROLLER_CPP
#define PLAYER_CONTROLLER_CPP

#include "../headers/PlayerController.h"

PlayerController::PlayerController(Player &player, Field &field) : player_(player), field_(field) {}

void PlayerController::addScore(int score_change) {
    player_.set_score(player_.score() + score_change);
}

void PlayerController::move(Sides side) {
    int x = player_.coordinates().x;
    int y = player_.coordinates().y;
    int speed = player_.speed();

    int direction_sign = 1;
    bool doesChangeX = false;
    if(side == Sides::LEFT || side == Sides::UP)
        direction_sign = -1;

    if(side == Sides::RIGHT || side == Sides::LEFT)
        doesChangeX = true;

    for(int i = 1; i <= speed; i++) {
        if(doesChangeX && !field_.isPassable({x + i * direction_sign, y})) {
            player_.set_coordinates(x + (i - 1) * direction_sign, y);
            return;
        } else if(!doesChangeX && !field_.isPassable({x, y + i * direction_sign})) {
            player_.set_coordinates(x, y + (i - 1) * direction_sign);
            return;
        }
    }

    if(doesChangeX) {
        if(field_.isPassable({x + speed * direction_sign, y}))
            player_.set_coordinates(x + speed * direction_sign, y);
    } else {
        if (field_.isPassable({x, y + speed * direction_sign}))
            player_.set_coordinates(x, y + speed * direction_sign);
    }
}

void PlayerController::set_field(Field &field) {
    field_ = field;
}

void PlayerController::addHealthPoints(int health_change) {
    player_.set_health_points(player_.health_points() + health_change);
}

bool PlayerController::doesAlive() {
    return player_.doesAlive();
}

Point PlayerController::get_coordinates() {
    return player_.coordinates();
}

#endif
