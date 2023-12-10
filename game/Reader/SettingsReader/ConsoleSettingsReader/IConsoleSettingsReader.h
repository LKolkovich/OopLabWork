#ifndef CODE_ISETTINGSREADER_H
#define CODE_ISETTINGSREADER_H

#include "../../../../utilityDataTypes/BiMap.h"
#include "../../../Commands/CommandsContainer.h"

class IConsoleSettingsReader {
public:
    virtual void read(std::map<char, CommandsContainer::Commands> &keys) = 0;
    virtual ~IConsoleSettingsReader() = default;
};

#endif //CODE_ISETTINGSREADER_H
