#ifndef CODE_INTERPRETATORINTERFACE_H
#define CODE_INTERPRETATORINTERFACE_H

#include "../Commands/CommandsContainer.h"
#include <map>
#include <string>
#include <stdexcept>
#include "../Reader/SettingsReader/FileSettingsReader/DefaultFileSettingsReader/DefaultFileSettingsReader.h"

class InterpreterInterface {
public:
    static void settingsFromFile(std::string path);
    virtual CommandsContainer::Commands toCommand(char symbol) const = 0;
    virtual bool hasCommand(char symbol) const = 0;
    virtual ~InterpreterInterface() = default;
protected:
    static std::map<char, CommandsContainer::Commands> key_map_;
};

#endif //CODE_INTERPRETATORINTERFACE_H
