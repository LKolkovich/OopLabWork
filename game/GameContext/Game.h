#ifndef CODE_GAME_H
#define CODE_GAME_H

#include "../../player/headers/PlayerController.h"
#include "../../field/headers/Field.h"
#include "../GameState/State.h"
#include "../View/GameView/AbstractView/AbstractGameView.h"
#include "../Reader/CommandReader/StartReader.h"
#include "../../FieldBuilder/FieldBuilder.h"
#include "../Reader/interface/AbstractReader.h"

class Game {
public:
    Game(PlayerController& controller, AbstractReader &reader);
    void start();
    void set_field(Field* field);
    void runGameLoop();
    void pickPremadeLevel(int number);
    void levelFromFile(const std::string &path);
    void movePlayer(Sides direction);
    void quit();
    void restart();

private:
    void runMainMenu();

    PlayerController& controller_;
    AbstractReader &reader_;
};


#endif //CODE_GAME_H
