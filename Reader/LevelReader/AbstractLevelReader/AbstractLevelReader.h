#ifndef CODE_ABSTRACTLEVELREADER_H
#define CODE_ABSTRACTLEVELREADER_H

#include "../../interface/ReaderInterface.h"
#include "../../../GameContext/Game.h"
#include "../../AbstractReader/AbstractReader.h"



class AbstractLevelReader : public AbstractReader {
public:
    AbstractLevelReader(Game *game);
protected:
    Game *game_;
};

#endif //CODE_ABSTRACTLEVELREADER_H
