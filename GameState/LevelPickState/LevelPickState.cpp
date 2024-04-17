#include "LevelPickState.h"
#include "../../View/HelpView/PathToLevelView/PathToLevelView.h"
#include "../../View/PreMadeLevelView/PreMadeLevelView.h"
#include "../../ViewInitializer/PreMadeLevelViewInitializer/PreMadeLevelViewInitializer.h"
#include "../../Reader/LevelReader/PreMadeLevelReader/PreMadeLevelReader.h"
#include "../../Reader/LevelReader/PathLevelReader/PathLevelReader.h"


void LevelPickState::handle(Commands cmd) {
    switch (cmd) {
        case Commands::QUIT: {
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new MenuView;
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            gameContext_->goToState(new MenuState);
            break;
        }
        case Commands::MOVE_UP: {
            AbstractPreMadeLevelView *view = new PreMadeLevelView;
            auto reader = new PreMadeLevelReader(gameContext_);
            gameContext_->unregisterReader();
            gameContext_->registerSubj(reader);
            gameContext_->setReader(reader);
            gameContext_->set_view_initializer(new PreMadeLevelViewInitializer(view));
            gameContext_->goToState(new LevelReadState);
            break;
        }
        case Commands::MOVE_DOWN: {
            AbstractInterpreter *interpreter = new DefaultInterpreter;
            AbstractHelpView *view = new PathToLevelView;
            auto reader = new PathLevelReader(gameContext_);
            gameContext_->unregisterReader();
            gameContext_->registerSubj(reader);
            gameContext_->setReader(reader);
            gameContext_->set_view_initializer(new SettingsViewInitializer(interpreter, view));
            gameContext_->goToState(new LevelReadState);
            break;
        }
    }
}