#include "AbstractReader.h"

void AbstractReader::makeCommandMessage(char symbol, Commands command) {
    removeMessage();
    message_ = new CommandInputMessage(symbol, command);
}

void AbstractReader::makeNoCommandMessage(char symbol) {
    removeMessage();
    message_ = new NoCommandInputMessage(symbol);
}