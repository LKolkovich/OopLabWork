#ifndef PLAYER_CONTROLLER_CPP
#define PLAYER_CONTROLLER_CPP

#include "../headers/PlayerController.h"
#include "../../field/headers/Field.h"

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

    Point tempCoords{0, 0};
    for(int i = 1; i <= speed; i++) {
        if(doesChangeX) {
            tempCoords = {x + i * direction_sign, y};
            if(!field_.isPassable(tempCoords)) {
                set_coordinates(x + (i - 1) * direction_sign, y);
                return;
            }
        } else {
            tempCoords = {x, y + i * direction_sign};
            if(!field_.isPassable(tempCoords)) {
                set_coordinates(x, y + (i - 1) * direction_sign);
                return;
            }
        }
    }

    if(field_.isPassable(tempCoords)) {
        player_.set_coordinates(tempCoords);
        triggerEvent(tempCoords);
    }
}


void PlayerController::set_coordinates(int x, int y) {
    set_coordinates(Point{x, y});
}

void PlayerController::set_coordinates(Point coordinates) {
    if(field_.isPassable(coordinates)) {
        player_.set_coordinates(coordinates);
        triggerEvent(coordinates);
    }
}

void PlayerController::triggerEvent(Point coordinates) {
    if (field_.getCell(coordinates).isEvent()) {
        field_.getCell(coordinates).execute_event(*this);
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

int PlayerController::get_health_points() const {
    return player_.health_points();
}

int PlayerController::get_score() const {
    return player_.score();
}

Field& PlayerController::field() const {
    return field_;
}

#endif
