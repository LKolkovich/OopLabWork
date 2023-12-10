#ifndef CODE_GAMEREADER_H
#define CODE_GAMEREADER_H
#include "../../Interpretator/DefaultInterpreter.h"
#include "../interface/AbstractReader.h"
#include "../../GameContext/Game.h"
#include "../../Commands/CommandsContainer.h"
#include <string>
#include <iostream>
#include <map>

class GameReader : public AbstractReader {
public:
    CommandsContainer::Commands read() override;
    ~GameReader() override = default;
};


#endif //CODE_GAMEREADER_H
