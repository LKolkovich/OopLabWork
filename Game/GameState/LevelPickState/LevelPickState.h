#ifndef CODE_LEVELPICKSTATE_H
#define CODE_LEVELPICKSTATE_H

#include "../MenuState/MenuState.h"
#include "../../View/HelpView/ConsoleSettingsView/ConsoleSettingsView.h"
#include "../LevelReadState/LevelReadState.h"

class LevelPickState : public AbstractState{
public:
    void handle(Commands cmd) override;
    ~LevelPickState() override = default;
};


#endif //CODE_LEVELPICKSTATE_H
