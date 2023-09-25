#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "../headers/Player.h"

Player::Player() {
    health_points_ = MAX_HEALT_POINTS;
    x_coordinate_ = START_X;
    y_coordinate_ = START_Y;
    score_ = 0;
    speed_ = START_SPEED;
}

bool Player::doesAllive(){
    return health_points_ != 0;
}

void Player::set_health_points(int health_points){
    if(health_points <= 0) {
        health_points_ = 0;
    }else if(health_points >= MAX_HEALT_POINTS) {
        health_points = MAX_HEALT_POINTS;
    }
    health_points_ = health_points;
}

int Player::set_speed(int speed) {
    if(speed <= 0) {
        return -1;
    }else if(speed >= MAX_SPEED) {
        speed_ = MAX_SPEED;
        return 0;
    }

    speed_ = speed;
    return 0;
}

void Player::set_score(int score) {
    score_ = score;
}

void Player::set_y_coordinate(int y) {
    y_coordinate_ = y;
}

void Player::set_x_coordinate(int x) {
    x_coordinate_ = x;
}

void Player::set_coordinates(int x, int y) {
    x_coordinate_ = x;
    y_coordinate_ = y;
}

int Player::x_coordinate() {
    return x_coordinate_;
}

int Player::y_coordinate() {
    return y_coordinate_;
}

int Player::speed() {
    return speed_;
}

int Player::health_points() {
    return health_points_;
}

int Player::score() {
    return score_;
}

#endif