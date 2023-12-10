#include "CommandsContainer.h"

#include <stdexcept>

std::vector<CommandsContainer::Commands> CommandsContainer::allCommands() {
    std::vector<CommandsContainer::Commands> result;
    for(int i = 0; static_cast<Commands>(i) != CommandsContainer::Commands::LAST; i++) {
        result.push_back(static_cast<CommandsContainer::Commands>(i));
    }
    return result;
}

CommandsContainer::Commands CommandsContainer::strToCommand(std::string str) {
    auto pos = strEqu.find(str);
    if(pos == strEqu.end()) {
        throw std::out_of_range("wrong command name");
    }
    return strEqu[str];
}

std::map<std::string, CommandsContainer::Commands> CommandsContainer::strEqu = {
        {"UP", Commands::MOVE_UP},
        {"DOWN", Commands::MOVE_DOWN},
        {"LEFT", Commands::MOVE_LEFT},
        {"RIGHT", Commands::MOVE_RIGHT},
        {"QUIT", Commands::QUIT},
        {"START", Commands::START}
};