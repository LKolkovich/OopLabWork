#ifndef CODE_GAMEVIEW_H
#define CODE_GAMEVIEW_H

#include "../../../game/GameContext/Game.h"
#include "AbstractGameView/AbstractGameView.h"

class GameView : public AbstractGameView {
public:
    void update(std::vector<std::string> &output) override;
    ~GameView() override = default;
};


#endif //CODE_GAMEVIEW_H
