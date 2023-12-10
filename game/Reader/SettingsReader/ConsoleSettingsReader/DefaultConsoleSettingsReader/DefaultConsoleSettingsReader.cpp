#include "DefaultConsoleSettingsReader.h"


void DefaultConsoleSettingsReader::read(std::map<char, CommandsContainer::Commands> &keys) {
    char symbol;
    std::string commandStr;
    std::cin >> symbol >> commandStr;
    auto command = CommandsContainer::strToCommand(commandStr);

    auto pos = keys.find(symbol);
    if(pos != keys.end()) {
        throw std::invalid_argument("this key already used");
    }

    for (const auto &item: keys) {
        if(item.second == command) {
            keys.erase(item.first);

        }
    }

    keys.insert(std::pair<char, CommandsContainer::Commands>(symbol, command));
}
