#include "DefaultInterpreter.h"

#include <stdexcept>

bool DefaultInterpreter::hasCommand(char symbol) const {
    auto pos = key_map_.find(symbol);
    return pos != key_map_.end();
}

Commands DefaultInterpreter::toCommand(char symbol) const {
    if(!hasCommand(symbol)) {
        throw std::invalid_argument("invalid command symbol " + std::string(1, symbol) + " \n");
    }
    return key_map_.at(symbol);
}

char DefaultInterpreter::toChar(Commands cmd) {
    for (auto it = key_map_.begin(); it != key_map_.end(); it++)
    {
        if(it->second == cmd) {
            return it->first;
        }
    }
    throw std::out_of_range("this command doesn`t have char equivalent yet");
}

