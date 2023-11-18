#ifndef CODE_INGAMESTATE_H
#define CODE_INGAMESTATE_H

#include "../AbstractState/AbstractState.h"
#include "../../GameContext/Game.h"
#include "../MenuState/MenuState.h"
#include "../EndGameState/EndGameState.h"
#include "../../View/HelpView/WInView/WinView.h"
#include "../../View/HelpView/LoseView/LoseView.h"

class InGameState : public AbstractState {
public:
    void handle(Commands cmd) override;
    ~InGameState() override = default;
};


#endif //CODE_INGAMESTATE_H
