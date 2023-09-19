#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    int health_points();
    int DealDamage(int damage);
    int score();
    void AddScore(int points);


private:
    int health_points_;
    int score_;
    const int MAX_HEALT_POINTS = 10;
};

#endif