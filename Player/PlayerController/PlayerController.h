#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../Player/Player.h"
#include <utility>
#include "../../Field/Point/Point.h"

class Field;

class PlayerController {
public:
    PlayerController(Player &player);
    PlayerController(Player &player, Field *field);
    ~PlayerController();
    void move(Sides side);
    void addHealthPoints(int health_change);
    void addScore(int score_change);
    bool doesAlive();
    Point get_coordinates();
    void set_field(Field *field);
    void set_coordinates(Point coordinates);
    void set_coordinates(int x, int y);
    int get_health_points() const;
    int get_score() const;
    Field* field() const;
    void resetPlayer();
    void addSpeed(int speed_change);

private:
    void triggerEvent(Point coordinates);
    void removeField();

    Player &player_;
    Field *field_;
};

#endif
