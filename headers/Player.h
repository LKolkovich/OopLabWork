#ifndef PLAYER_H
#define PLAYER_H

#include "Sides.h"
#include <string>
#include <iostream>

class Player {
public:
    Player();
    int health_points();
    void set_health_points(int health_points);
    int score();
    void set_score(int score);
    int x_coordinate();
    int y_coordinate();
    void set_coordinates(int x, int y);
    void set_x_coordinate(int x);
    void set_y_coordinate(int y);
    int speed();
    int set_speed(int speed);
    bool doesAllive();

private:
    int speed_;
    int health_points_;
    int score_;
    int x_coordinate_;
    int y_coordinate_;
    const int MAX_SPEED = 5;
    const int MAX_HEALT_POINTS = 10;
    const int START_X = 0;
    const int START_Y = 0;
    const int START_SPEED = 1;
};

#endif