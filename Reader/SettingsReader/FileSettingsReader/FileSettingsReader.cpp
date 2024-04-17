#include "FileSettingsReader.h"

#include <fstream>
#include "../../../Interpretor/DefaultInterpreter.h"

FileSettingsReader::FileSettingsReader() {
    message_ = nullptr;
    id_ = global_id++;
}

Commands FileSettingsReader::read() {
    std::string path;
    std::cin >> path;
    DefaultInterpreter interpreter;
    if(path.size() == 1 && interpreter.toCommand(path[0]) == Commands::QUIT) {
        makeCommandMessage(path[0], QUIT);
        return Commands::QUIT;
    }
    interpreter.clear();
    readOnStart(path);
    return Commands::QUIT;
}

void FileSettingsReader::readOnStart(const std::string &path) {
    std::string str;
    std::string tempStr;
    std::ifstream file;
    file.open(path);
    if(file.is_open()) {
        for(int i = 0; static_cast<Commands>(i) != LAST; i++) {
            char c = '\0';
            str = " ";
            file >> c;
            file >> str;
            if(str == " " || c == '\0') {
                throw std::invalid_argument("wrong value in settings file");
            }
            Commands cmd = CommandsContainer::strToCommand(str);

            AbstractInterpreter::addCommand(std::pair<char, Commands>(c, cmd));

        }
    }
}