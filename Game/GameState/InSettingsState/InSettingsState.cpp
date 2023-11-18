#include "InSettingsState.h"
#include "../../ViewInitializer/MapViewInitializer/MapViewInitializer.h"

void InSettingsState::handle(Commands cmd) { // достаточно одного потому что работает по единой логике для
    // обоих ридеров
    // однако ридеров будет 2, как и представлений
    if(cmd == Commands::QUIT) {
        AbstractInterpreter *interpreter = new DefaultInterpreter;
        AbstractHelpView *view = new SettingsMenuView;
        gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
        gameContext_->setReader(new GameReader);
        gameContext_->goToState(new SettingsMenuState);
    }
}