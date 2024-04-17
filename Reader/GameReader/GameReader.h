#ifndef CODE_GAMEREADER_H
#define CODE_GAMEREADER_H
#include "../../Interpretor//DefaultInterpreter.h"
#include "../interface/ReaderInterface.h"
#include "../../GameContext/Game.h"
#include "../../Commands/CommandsContainer/CommandsContainer.h"
#include <string>
#include <iostream>
#include <map>
#include "../AbstractReader/AbstractReader.h"

class GameReader : public AbstractReader {
public:
    GameReader();
    Commands read() override;
    ~GameReader() override = default;
};


#endif //CODE_GAMEREADER_H
