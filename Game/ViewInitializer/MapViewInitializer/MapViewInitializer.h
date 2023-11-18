#ifndef CODE_MAPVIEWINITIALIZER_H
#define CODE_MAPVIEWINITIALIZER_H

#include "../ViewInitializerInterface.h"
#include "../../../Field/Field/Field.h"
#include "../../GameContext/Game.h"
#include "../../View/GameView/AbstractGameView/AbstractGameView.h"
#include <typeinfo>

class MapViewInitializer : public ViewInitializerInterface {
public:
    MapViewInitializer(Game *game, AbstractGameView *view);
    void init() override;
    ~MapViewInitializer() override;
private:
    Game *game_;
    AbstractGameView *view_;

    char eventToChar(EventInterface* event);
};


#endif //CODE_MAPVIEWINITIALIZER_H
