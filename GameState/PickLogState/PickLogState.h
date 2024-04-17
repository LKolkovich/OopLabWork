#ifndef CODE_PICKLOGSTATE_H
#define CODE_PICKLOGSTATE_H

#include "../AbstractState/AbstractState.h"
#include "../../GameContext/Game.h"
#include "../../Logging/StreamWrapper/FileStreamWrapper/FileStreamWrapper.h"
#include "../../Logging/StreamWrapper/ConsoleStreamWrapper/ConsoleStreamWrapper.h"

class PickLogState : public AbstractState {
public:
    void handle(Commands cmd) override;
    ~PickLogState() override = default;
};


#endif //CODE_PICKLOGSTATE_H
