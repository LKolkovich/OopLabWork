#include "CommandsContainer.h"

#include <stdexcept>

std::vector<Commands> CommandsContainer::allCommands() {
    std::vector<Commands> result;
    for(int i = 0; static_cast<Commands>(i) != Commands::LAST; i++) {
        result.push_back(static_cast<Commands>(i));
    }
    return result;
}

Commands CommandsContainer::strToCommand(std::string str) {
    auto pos = CommandsContainer::strEqu.find(str);
    if(pos == CommandsContainer::strEqu.end()) {
        throw std::out_of_range("wrong command name");
    }
    return CommandsContainer::strEqu.at(str);
}

const std::unordered_map<std::string, Commands> CommandsContainer::strEqu = {
        {"UP", Commands::MOVE_UP},
        {"DOWN", Commands::MOVE_DOWN},
        {"LEFT", Commands::MOVE_LEFT},
        {"RIGHT", Commands::MOVE_RIGHT},
        {"START", Commands::START},
        {"QUIT", Commands::QUIT},
        {"SETTINGS", Commands::SETTINGS}
};
