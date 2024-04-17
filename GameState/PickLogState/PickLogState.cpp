#include "PickLogState.h"

void PickLogState::handle(Commands cmd) {
    switch (cmd) {
        case Commands::MOVE_UP:
            gameContext_->addStreamToObserver(new ConsoleStreamWrapper);
            break;
        case Commands::MOVE_DOWN:
            gameContext_->addStreamToObserver(new FileStreamWrapper);
            break;
        case Commands::MOVE_LEFT:
            gameContext_->addStreamToObserver(new ConsoleStreamWrapper);
            gameContext_->addStreamToObserver(new FileStreamWrapper);
            break;
        case Commands::QUIT:
            gameContext_->quit();
            break;
    }

    AbstractInterpreter *interpreter = new DefaultInterpreter;
    AbstractHelpView *view = new MenuView;
    gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
    gameContext_->goToState(new MenuState);
}