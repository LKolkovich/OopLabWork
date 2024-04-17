#include "InSettingsState.h"

void InSettingsState::handle(Commands cmd) {
    if(cmd == Commands::QUIT) {
        AbstractInterpreter *interpreter = new DefaultInterpreter;
        AbstractHelpView *view = new SettingsMenuView;
        gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
        auto reader = new GameReader;
        gameContext_->unregisterReader();
        gameContext_->registerSubj(reader);
        gameContext_->setReader(reader);
        gameContext_->goToState(new SettingsMenuState);
    }
}