#ifndef CODE_COMMANDREADER_CPP
#define CODE_COMMANDREADER_CPP

#include "StartReader.h"
#include "../GameReader/GameReader.h"

CommandsContainer::Commands StartReader::read() {
    char input;
    std::cin >> input;
    //return convertString(input);
    DefaultInterpreter interpreter;
    return interpreter.toCommand(input);
}


#endif