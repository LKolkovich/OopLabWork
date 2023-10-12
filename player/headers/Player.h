#ifndef PLAYER_H
#define PLAYER_H

#include "Sides.h"
#include "../../field/headers/Point.h"

class Player {
public:
    Player();
    int health_points() const;
    void set_health_points(int health_points);
    int score() const;
    void set_score(int score);
    void set_coordinates(int x, int y);
    void set_x_coordinate(int x);
    void set_y_coordinate(int y);
    Point coordinates() const;
    int speed() const;
    int set_speed(int speed);
    bool doesAlive() const;

private:
    int speed_;
    int health_points_;
    int score_;
    Point coordinates_;
    const int MAX_SPEED = 5;
    const int MAX_HEALTH_POINTS = 10;
    const int START_X = 0;
    const int START_Y = 0;
    const int START_SPEED = 1;
};

#endif
