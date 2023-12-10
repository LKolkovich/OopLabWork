#ifndef PLAYER_H
#define PLAYER_H

#include "Sides.h"
#include "../../field/headers/Point.h"
#define MAX_SPEED 5
#define MAX_HEALTH_POINTS 10
#define START_COORD 0
#define START_SPEED 1


class Player {
public:
    Player();
    Player(const Player& other);
    Player(Player&& other);
    Player& operator=(const Player& other);
    Player& operator=(Player&& other);

    int health_points() const;
    void set_health_points(int health_points);
    int score() const;
    void set_score(int score);
    void set_coordinates(int x, int y);
    void set_coordinates(Point coordinates);
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
};

#endif
