#include "SettingsMenuState.h"

void SettingsMenuState::handle(Commands cmd) {
    switch (cmd) {
        case Commands::QUIT: {
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new MenuView;
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            gameContext_->goToState(new MenuState);
            break;
        } case Commands::MOVE_UP: {
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new ConsoleSettingsView;
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            auto reader = new ConsoleSettingsReader;
            gameContext_->unregisterReader();
            gameContext_->registerSubj(reader);
            gameContext_->setReader(reader);

            gameContext_->goToState(new InSettingsState);
            break;
        } case Commands::MOVE_DOWN: {
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new FileSettingsView;
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            auto reader = new FileSettingsReader;
            gameContext_->unregisterReader();
            gameContext_->registerSubj(reader);
            gameContext_->setReader(reader);

            gameContext_->goToState(new InSettingsState);
        }
    }
}
