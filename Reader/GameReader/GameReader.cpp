#include "GameReader.h"

GameReader::GameReader() {
    message_ = nullptr;
    id_ = global_id++;
}

Commands GameReader::read() {
    DefaultInterpreter interpreter;
    char input;
    bool noCommand = true;
//    while (noCommand) {
//        std::cin >> input;
//        if(interpreter.hasCommand(input)) {
//            makeCommandMessage(input, interpreter.toCommand(input));
//            noCommand = false;
//        } else {
//            makeNoCommandMessage(input);
//        }
//    }

    std::cin >> input;
    if(interpreter.hasCommand(input)) {
        makeCommandMessage(input, interpreter.toCommand(input));
        return interpreter.toCommand(input);
    } else {
        makeNoCommandMessage(input);
        return Commands::LAST;
    }
}
