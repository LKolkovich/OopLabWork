#ifndef CODE_ABSTRACTLEVELREADER_H
#define CODE_ABSTRACTLEVELREADER_H

#include "../../interface/ReaderInterface.h"
#include "../../../GameContext/Game.h"


class AbstractLevelReader : public ReaderInterface {
public:
    AbstractLevelReader(Game *game);
protected:
    Game *game_;
};

#endif //CODE_ABSTRACTLEVELREADER_H
