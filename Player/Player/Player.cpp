#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h"

Player::Player() : score_(0), health_points_(MAX_HEALTH_POINTS), speed_(START_SPEED), coordinates_({START_COORD, START_COORD}){}

Player::Player(Player &&other) : score_(0), health_points_(MAX_HEALTH_POINTS), speed_(START_SPEED), coordinates_({START_COORD, START_COORD}) {
    *this = std::move(other);
}

Player& Player::operator=(Player &&other){
    if(this != &other)
        std::swap(score_, other.score_);
        std::swap(health_points_, other.health_points_);
        std::swap(speed_, other.speed_);
        std::swap(coordinates_, other.coordinates_);
    return *this;
}

Player::Player(const Player &other) : score_(other.score_), health_points_(other.health_points_), speed_(other.speed_), coordinates_(other.coordinates_)  {}

Player& Player::operator=(const Player &other) {
    Player temp(other);
    std::swap(score_, temp.score_);
    std::swap(health_points_, temp.health_points_);
    std::swap(speed_, temp.speed_);
    std::swap(coordinates_, temp.coordinates_);
    return *this;
}

bool Player::doesAlive() const {
    return health_points_ != 0;
}

void Player::reset() {
    score_ = 0;
    health_points_ = MAX_HEALTH_POINTS;
    speed_ = START_SPEED;
    coordinates_ = {START_COORD, START_COORD};
}

void Player::set_health_points(int health_points) {
    if(health_points <= 0) {
        health_points_ = 0;
        return;
    }else if(health_points >= MAX_HEALTH_POINTS) {
        health_points = MAX_HEALTH_POINTS;
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
    coordinates_.y = y;
}

void Player::set_x_coordinate(int x) {
    coordinates_.x = x;
}

void Player::set_coordinates(int x, int y) {
    coordinates_.x = x;
    coordinates_.y = y;
}

void Player::set_coordinates(Point coordinates) {
    coordinates_ = coordinates;
}

int Player::speed() const {
    return speed_;
}

int Player::health_points() const {
    return health_points_;
}

int Player::score() const {
    return score_;
}

Point Player::coordinates() const {
    return coordinates_;
}

#endif
