#ifndef CODE_COMMANDREADER_H
#define CODE_COMMANDREADER_H

#include "../interface/AbstractReader.h"
#include "../../GameContext/Game.h"
#include <string>
#include <iostream>

class StartReader : public AbstractReader {
public:
    CommandsContainer::Commands read() override;
    ~StartReader() override = default;

private:
    void convertString(std::string input);
};


#endif //CODE_COMMANDREADER_H
