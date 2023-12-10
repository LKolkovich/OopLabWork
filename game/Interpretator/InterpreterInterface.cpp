#include "InterpreterInterface.h"


std::map<char, CommandsContainer::Commands> InterpreterInterface::key_map_= {};

void InterpreterInterface::settingsFromFile(std::string path) {
    DefaultFileSettingsReader reader;
    reader.read(key_map_, path);
}