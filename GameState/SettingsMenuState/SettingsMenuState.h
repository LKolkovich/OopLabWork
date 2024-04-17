#ifndef CODE_SETTINGSFROMCONSOLESTATE_H
#define CODE_SETTINGSFROMCONSOLESTATE_H

#include "../AbstractState/AbstractState.h"
#include "../../GameContext/Game.h"
#include "../InGameState/InGameState.h"
#include "../../Reader/GameReader/GameReader.h"
#include "../../View/HelpView/ConsoleSettingsView/ConsoleSettingsView.h"
#include "../../View/HelpView/FileSettingsView/FileSettingsView.h"
#include "../InSettingsState/InSettingsState.h"

class SettingsMenuState : public AbstractState{
    void handle(Commands cmd) override;
    ~SettingsMenuState() override = default;
};


#endif //CODE_SETTINGSFROMCONSOLESTATE_H
