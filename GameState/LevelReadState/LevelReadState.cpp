#include "LevelReadState.h"
#include "../../View/GameView/GameView.h"
#include "../../ViewInitializer/MapViewInitializer/MapViewInitializer.h"

void LevelReadState::handle(Commands cmd) {
    if(cmd == Commands::QUIT) {
        AbstractGameView *view = new GameView;
        gameContext_->set_view_initializer(new MapViewInitializer(gameContext_, view));
        auto reader = new GameReader;
        gameContext_->unregisterReader();
        gameContext_->registerSubj(reader);
        gameContext_->setReader(reader);

        gameContext_->goToState(new InGameState);
    }
}