#ifndef CODE_MENUSTATE_H
#define CODE_MENUSTATE_H
#include "../AbstractState/AbstractState.h"
#include "../InGameState/InGameState.h"
#include "../SettingsMenuState/SettingsMenuState.h"
#include "../../View/HelpView/SettingsMenuView/SettingsMenuView.h"
#include "../../Reader/SettingsReader/ConsoleSettingsReader/ConsoleSettingsReader.h"
#include "../../Reader/SettingsReader/FileSettingsReader/FileSettingsReader.h"
#include "../LevelPickState/LevelPickState.h"
#include "../../View/HelpView/PickLevelView/PickLevelView.h"


class Game;

class MenuState : public AbstractState {
public:
    void handle(Commands cmd) override;
    ~MenuState() override = default;
};


#endif //CODE_MENUSTATE_H
