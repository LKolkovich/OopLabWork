#ifndef CODE_IFILESETTINGSREADER_H
#define CODE_IFILESETTINGSREADER_H

#include "../../../Commands/CommandsContainer.h"

#include <string>
#include <map>

class IFileSettingsReader {
public:
    virtual void read(std::map<char, CommandsContainer::Commands> &keys, std::string path) = 0;
    virtual ~IFileSettingsReader() = default;
};

#endif //CODE_IFILESETTINGSREADER_H
