#include "GameReader.h"

CommandsContainer::Commands GameReader::read() {
    DefaultInterpreter interpreter;
    char input;
    do {
    std::cin >> input;
    } while (!interpreter.hasCommand(input));
    return interpreter.toCommand(input);
}
