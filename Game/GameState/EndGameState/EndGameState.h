#ifndef CODE_ENDGAMESTATE_H
#define CODE_ENDGAMESTATE_H

#include "../../GameContext/Game.h"
#include "../MenuState/MenuState.h"
#include "../../View/HelpView/MenuView/MenuView.h"

class EndGameState : public AbstractState {
public:
    void handle(Commands cmd) override;
    ~EndGameState() override = default;
};


#endif //CODE_ENDGAMESTATE_H
