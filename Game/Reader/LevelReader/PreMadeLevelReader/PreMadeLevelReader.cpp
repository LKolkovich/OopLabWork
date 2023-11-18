#include "PreMadeLevelReader.h"

PreMadeLevelReader::PreMadeLevelReader(Game *game) : AbstractLevelReader(game) {}

Commands PreMadeLevelReader::read() {
    int levelNum;
    std::cin >> levelNum;
    game_->pickPremadeLevel(levelNum);
    return Commands::QUIT;
}