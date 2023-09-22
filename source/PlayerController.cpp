#ifndef PLAYER_CONTROLLER_CPP
#define PLAYER_CONTROLLER_CPP

#include "../headers/PlayerController.h"

PlayerController::PlayerController(Player *player) {
    player_ = player;
}

void PlayerController::add_score(int score_change){
    player_->set_score(player_->score() + score_change);
}

int PlayerController::move(Sides side) {
    int speed = player_->speed();
    int x = player_->x_coordinate();
    int y = player_->y_coordinate();
    
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

    player_->set_coordinates(x, y);
    return 0;
}

int PlayerController::add_health_points(int health_change) {
    if(player_->set_health_points(player_->health_points() + health_change) == 1) {
        std::cout << "game over\n";
        return 1;
    }
    return 0;
}

std::pair<int, int> PlayerController::get_coordinates() {
    return std::make_pair(player_->x_coordinate(), player_->y_coordinate());
}

#endif