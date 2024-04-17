#ifndef CODE_INTERPRETATORINTERFACE_H
#define CODE_INTERPRETATORINTERFACE_H

#include "../Commands/CommandsContainer/CommandsContainer.h"
#include <map>
#include <string>
#include <stdexcept>


class AbstractInterpreter {
public:
    static void changeCommand(std::pair<char, Commands> pair);
    static void addCommand(std::pair<char, Commands> pair);
    virtual Commands toCommand(char symbol) const = 0;
    virtual bool hasCommand(char symbol) const = 0;
    virtual char toChar(Commands cmd) = 0;
    void clear();
    virtual ~AbstractInterpreter() = default;
protected:
    static std::map<char, Commands> key_map_;
};

#endif //CODE_INTERPRETATORINTERFACE_H
