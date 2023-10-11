#ifndef PLAYER_CONTROLLER_CPP
#define PLAYER_CONTROLLER_CPP

#include "../headers/PlayerController.h"

PlayerController::PlayerController(Player &player) : player_(player) {} // поменять на адрес или сделать проверку на нулптр, но лучше поменять на адре

void PlayerController::add_score(int score_change) {
    player_.set_score(player_.health_points() + score_change);
}

int PlayerController::move(Sides side) {
    int speed = player_.speed();
    int x = player_.x_coordinate();
    int y = player_.y_coordinate();
    
    switch (side) {
    case Sides::UP:
        y -= speed;
        break;
    case Sides::DOWN:
        y += speed;
        break;
    case Sides::LEFT:
        x -= speed;
        break;
    case Sides::RIGHT:
        x += speed;
        break;
    }

    player_.set_coordinates(x, y);
    return 0;
}

void PlayerController::add_health_points(int health_change) { // сделать двумя методами: 1 для изменения хп, вторрой для проверки на живой/не живой
// точно так же сделать в классе игрока
    player_.set_health_points(player_.health_points() + health_change);
}

bool PlayerController::doesAllive(){
    return player_.doesAllive();
}

std::pair<int, int> PlayerController::get_coordinates() {
    return std::make_pair(player_.x_coordinate(), player_.y_coordinate());
}

#endif