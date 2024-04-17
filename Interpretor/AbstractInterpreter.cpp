#include "AbstractInterpreter.h"


std::map<char, Commands> AbstractInterpreter::key_map_= {};

void AbstractInterpreter::clear() {
    key_map_.clear();
}


void AbstractInterpreter::addCommand(std::pair<char, Commands> pair) {
    for (const auto &item: key_map_) {
        if(item.second == pair.second) {
            throw std::invalid_argument("one command can`t have two keys as its trigger");
        }
    }

    auto pos = key_map_.find(pair.first);
    if(pos != key_map_.end()) {
        throw std::invalid_argument("this key already used");
    }


    key_map_.insert(pair);
}

void AbstractInterpreter::changeCommand(std::pair<char, Commands> pair) {
    auto pos = key_map_.find(pair.first);
    if(pos != key_map_.end()) {
        throw std::invalid_argument("this key already used");
    }

    for (auto it = key_map_.begin(); it != key_map_.end(); ) {
        if (it->second == pair.second) {
            it = key_map_.erase(it);
        } else {
            it++;
        }
    }

    key_map_.insert(std::pair<char, Commands>(pair.first, pair.second));
}