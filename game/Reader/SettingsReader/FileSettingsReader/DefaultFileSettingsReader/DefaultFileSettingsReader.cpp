#include "DefaultFileSettingsReader.h"

#include <fstream>

void DefaultFileSettingsReader::read(std::map<char, CommandsContainer::Commands> &keys, std::string path) {
    std::string str; // мб сделать проверку на правильность считывания
    std::string tempStr;
    std::ifstream file;
    file.open(path);
    if(file.is_open()) {
        for(int i = 0; static_cast<CommandsContainer::Commands>(i) != CommandsContainer::LAST; i++) {
            char c = '\0';
            str = " ";
            file >> c;
            file >> str;
            if(str == " " || c == '\0') {
                throw std::invalid_argument("wrong value in settings file");
            }

            CommandsContainer::Commands cmd = CommandsContainer::strToCommand(str);
            auto pos = keys.find(c);
            if(pos != keys.end()) {
                throw std::invalid_argument("this key already used");
            }

            for (const auto &item: keys) {
                if(item.second == cmd) {
                    throw std::invalid_argument("one command can`t have two keys as its trigger");
                }
            }
            keys.insert(std::pair<char, CommandsContainer::Commands>(c, cmd));
        }
    }
}