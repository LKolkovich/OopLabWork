#include "LevelReadState.h"
#include "../../View/GameView/GameView.h"
#include "../../ViewInitializer/MapViewInitializer/MapViewInitializer.h"

void LevelReadState::handle(Commands cmd) {
    if(cmd == Commands::QUIT) {
        AbstractGameView *view = new GameView;
        gameContext_->set_view_initializer(new MapViewInitializer(gameContext_, view));
        gameContext_->setReader(new GameReader);
        gameContext_->goToState(new InGameState);
    }
}