#include "InGameState.h"

void InGameState::handle(Commands cmd) {
    switch (cmd) {
        case Commands::QUIT: {
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new MenuView;
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            gameContext_->goToState(new MenuState);
            break;
        }
        case Commands::MOVE_RIGHT:
        case Commands::MOVE_LEFT:
        case Commands::MOVE_UP:
        case Commands::MOVE_DOWN:
            gameContext_->movePlayer(static_cast<Sides>(cmd)); //check if he win or lose
            if(gameContext_->isWin()) {
                AbstractInterpreter *interpreter = new DefaultInterpreter;
                AbstractHelpView *view = new WinView;
                gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
                gameContext_->goToState(new EndGameState);
                break;
            }
            if(gameContext_->isLose()) {
                AbstractInterpreter *interpreter = new DefaultInterpreter;
                AbstractHelpView *view = new LoseView;
                gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
                gameContext_->goToState(new EndGameState);
                break;
            }
            break;

    }
}
