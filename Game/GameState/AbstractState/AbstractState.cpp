#include "AbstractState.h"
#include <stdexcept>

AbstractState::AbstractState() : gameContext_(nullptr) {}

void AbstractState::setGameContext(Game *gameContext) {
    if(gameContext == nullptr) {
        throw std::invalid_argument("Game can`t be nullptr in state");
    }
    gameContext_ = gameContext;
}