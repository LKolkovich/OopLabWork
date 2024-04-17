#include "ConsoleSettingsReader.h"
#include "../../../Interpretor/DefaultInterpreter.h"

ConsoleSettingsReader::ConsoleSettingsReader() {
    message_ = nullptr;
    id_ = global_id++;
}

Commands ConsoleSettingsReader::read() {
    char symbol;
    std::string commandStr;
    std::cin >> symbol;
    DefaultInterpreter interpreter;
    if(interpreter.hasCommand(symbol) && interpreter.toCommand(symbol) == Commands::QUIT) {
        makeCommandMessage(symbol, QUIT);
        return Commands::QUIT;
    }

    std::cin >> commandStr;

    auto command = CommandsContainer::strToCommand(commandStr);
    interpreter.changeCommand(std::pair<char, Commands>(symbol, command));
    return Commands::QUIT;
}
