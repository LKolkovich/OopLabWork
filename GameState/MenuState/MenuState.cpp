#include "MenuState.h"
#include "../../View/GameView/GameView.h"
#include "../../ViewInitializer/MapViewInitializer/MapViewInitializer.h"

void MenuState::handle(Commands cmd) {
    switch (cmd) {
        case Commands::START: {
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new PickLevelView;
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            gameContext_->goToState(new LevelPickState);
            break;
        } case Commands::QUIT:
            gameContext_->quit();
            break;
        case Commands::SETTINGS:
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new SettingsMenuView;
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            gameContext_->goToState(new SettingsMenuState);
            break;
    }

}

