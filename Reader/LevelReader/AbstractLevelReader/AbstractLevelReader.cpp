#include "AbstractLevelReader.h"
#include <stdexcept>

AbstractLevelReader::AbstractLevelReader(Game *game) : game_(nullptr){
    if(game == nullptr) {
        throw std::invalid_argument("Game can`t be nullptr in level reader");
    }
    game_ = game;
    message_ = nullptr;
    id_ = global_id++;
}