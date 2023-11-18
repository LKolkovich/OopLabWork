#include "EndGameState.h"

void EndGameState::handle(Commands cmd) {
    if(cmd == Commands::QUIT) {
        AbstractInterpreter *interpreter = new DefaultInterpreter;
        AbstractHelpView *view = new MenuView;
        gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
        gameContext_->goToState(new MenuState);
    }
}