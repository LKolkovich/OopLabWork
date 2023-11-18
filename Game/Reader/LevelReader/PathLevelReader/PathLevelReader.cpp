#include "PathLevelReader.h"

PathLevelReader::PathLevelReader(Game *game) : AbstractLevelReader(game) {}

Commands PathLevelReader::read() {
    std::string input;
    std::cin >> input;
    game_->levelFromFile(input);
    return Commands::QUIT;
}