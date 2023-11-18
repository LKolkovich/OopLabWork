#ifndef CODE_ABSTRACTSTATE_H
#define CODE_ABSTRACTSTATE_H

#include "../../Commands/CommandsContainer/CommandsContainer.h"

class Game;

class AbstractState {
protected:
    Game* gameContext_;
public:
    AbstractState();
    virtual void handle(Commands cmd) = 0;

    void setGameContext(Game* gameContext);
    virtual ~AbstractState() = default;
};


#endif //CODE_ABSTRACTSTATE_H
