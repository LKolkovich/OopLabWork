#ifndef CODE_GAMEVIEW_H
#define CODE_GAMEVIEW_H


#include "../../IView.h"

class Game;

class AbstractGameView : public IView {
public:
    AbstractGameView(Game &game);
protected:
    Game &game_;
};


#endif //CODE_GAMEVIEW_H
