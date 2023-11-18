#ifndef CODE_GAME_H
#define CODE_GAME_H

#include "../../Player/PlayerController/PlayerController.h"
#include "../../Field/Field/Field.h"
#include "../GameState/AbstractState/AbstractState.h"
#include "../ViewInitializer/ViewInitializerInterface.h"
#include "../../Field/FieldBuilder/FieldBuilder.h"
#include "../Reader/interface/ReaderInterface.h"
#include "../GameState/MenuState/MenuState.h"
#include "../ViewInitializer/ViewInitializerInterface.h"
#include "../ViewInitializer/SettingsViewInitializer/SettingsViewInitializer.h"

class Game {
public:
    Game(PlayerController& controller, ReaderInterface *reader);
    ~Game();
    void start();
    void pickPremadeLevel(int number);
    void levelFromFile(const std::string &path);
    void movePlayer(Sides direction);
    void quit();
    void goToState(AbstractState* new_state);
    bool isWin();
    bool isLose();
    void setReader(ReaderInterface *reader);
    void set_view_initializer(ViewInitializerInterface *view);
    Field& field();
    Point playerPosition();
    int health_points();
    int score();

private:
    bool isRunning_;
    AbstractState* current_state_;
    PlayerController& controller_;
    ReaderInterface* reader_;
    ViewInitializerInterface *view_initializer_;

    void resetPlayer();
};


#endif //CODE_GAME_H
