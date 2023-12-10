#ifndef CODE_SETTINGSREADER_H
#define CODE_SETTINGSREADER_H

#include "../IConsoleSettingsReader.h"
#include "../../../../Interpretator/InterpreterInterface.h"

#include <iostream>

class DefaultConsoleSettingsReader : public IConsoleSettingsReader{
public:
    void read(std::map<char, CommandsContainer::Commands> &keys) override;
    ~DefaultConsoleSettingsReader() override = default;
};


#endif //CODE_SETTINGSREADER_H
