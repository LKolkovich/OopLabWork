#ifndef PLAYER_CONTROLLER_CPP
#define PLAYER_CONTROLLER_CPP

#include "PlayerController.h"
#include "../../Field/Field/Field.h"

PlayerController::PlayerController(Player &player) : player_(player), field_(nullptr) {}

PlayerController::PlayerController(Player &player, Field *field) : PlayerController(player) {
    if(field == nullptr) {
        throw std::invalid_argument("Field can`t be nullptr when it`s given to controller");
    }
    field_ = field;
}

void PlayerController::addScore(int score_change) {
    player_.set_score(player_.score() + score_change);
}

void PlayerController::move(Sides side) {
    if(field_ == nullptr) {
        throw std::invalid_argument("Field can`t be nullptr during the Game");
    }
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
            if(!field_->isPassable(tempCoords)) {
                set_coordinates(x + (i - 1) * direction_sign, y);
                return;
            }
        } else {
            tempCoords = {x, y + i * direction_sign};
            if(!field_->isPassable(tempCoords)) {
                set_coordinates(x, y + (i - 1) * direction_sign);
                return;
            }
        }
    }

    if(field_->isPassable(tempCoords)) {
        player_.set_coordinates(tempCoords);
        triggerEvent(tempCoords);
    }
}


void PlayerController::set_coordinates(int x, int y) {
    set_coordinates(Point{x, y});
}

void PlayerController::set_coordinates(Point coordinates) {
    if(field_ == nullptr) {
        throw std::invalid_argument("Field can`t be nullptr during the Game");
    }
    if(field_->isPassable(coordinates)) {
        player_.set_coordinates(coordinates);
        triggerEvent(coordinates);
    }
}

void PlayerController::triggerEvent(Point coordinates) {
    if(field_ == nullptr) {
        throw std::invalid_argument("Field can`t be nullptr during the Game");
    }
    if (field_->getCell(coordinates).isEvent()) {
        field_->getCell(coordinates).executeEvent(*this);
    }
}

void PlayerController::set_field(Field *field) {
    if(field == nullptr) {
        throw std::invalid_argument("Field can`t be nullptr during the Game");
    }
    removeField();
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

Field* PlayerController::field() const {
    return field_;
}

void PlayerController::removeField() {
    if(field_ != nullptr) {
        delete field_;
        field_ = nullptr;
    }
}

PlayerController::~PlayerController() {
    removeField();
}

void PlayerController::resetPlayer() {
    player_.reset();
}

void PlayerController::addSpeed(int speed_change) {
    player_.set_speed(player_.speed() + speed_change);
}

#endif
