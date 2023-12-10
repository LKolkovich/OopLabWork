#ifndef CODE_ABSTRACTMENUVIEW_H
#define CODE_ABSTRACTMENUVIEW_H

#include "../../Context/GameContext/GameContext.h"

class AbstractMenuView {
public:
    AbstractMenuView(GameContext &game);
protected:
    GameContext &game_;
};


#endif //CODE_ABSTRACTMENUVIEW_H
