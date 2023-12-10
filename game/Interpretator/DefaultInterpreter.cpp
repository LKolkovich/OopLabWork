#include "DefaultInterpreter.h"

#include <stdexcept>

bool DefaultInterpreter::hasCommand(char symbol) const {
    auto pos = key_map_.find(symbol);
    return pos != key_map_.end();
}

CommandsContainer::Commands DefaultInterpreter::toCommand(char symbol) const {
    if(!hasCommand(symbol)) {
        throw std::invalid_argument("invalid command symbol " + std::string(1, symbol) + " \n");
    }
    CommandsContainer::Commands command = key_map_.at(symbol);
    if(command == CommandsContainer::QUIT || command == CommandsContainer::START) {
        return key_map_.at(symbol); // ДОБАВИТЬ ЗАМЕНЯЕМОСТЬ КОМАНД
    }
    throw std::invalid_argument("wrong input in game context");
}
