#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "../headers/Player.h"

Player::Player() {
    health_points_ = MAX_HEALT_POINTS;
    score_ = 0;
}

int Player::DealDamage(int damage) {
    if (health_points_ == 0) {
        return -2;
    } else if (health_points_ - damage <= 0){
        health_points_ = 0;
        return -1;
    }
    health_points_ -= damage;
    return 0;
}

int Player::health_points() {
    return health_points_;
}

int Player::score() {
    return score_;
}

void Player::AddScore(int points) {
    score_ += points;
}

#endif