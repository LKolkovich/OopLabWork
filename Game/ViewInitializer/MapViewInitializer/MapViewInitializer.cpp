#include "MapViewInitializer.h"

MapViewInitializer::MapViewInitializer(Game *game, AbstractGameView *view) : game_(nullptr), view_(nullptr) {
    if(game == nullptr) {
        throw std::invalid_argument("Game can`t be nullptr");
    }
    if(view == nullptr) {
        throw std::invalid_argument("view can`t be nullptr");
    }
    game_ = game;
    view_ = view;
}

void MapViewInitializer::init() {
    std::vector<std::string> result;

    Field field = game_->field();
    Point playerPosition = game_->playerPosition();

    for(int i = 0; i < field.size().y; i++) {
        std::string temp;
        for(int j = 0; j < field.size().x; j++) {
            Point coords = {j, i};
            if(playerPosition == coords) {
                temp.push_back('P');
            } else if(coords == field.start()) {
                temp.push_back('!');
            } else if(coords == field.finish()) {
                temp.push_back('?');
            } else if (field.getCell(coords).isEvent()) {
                temp.push_back(eventToChar(field.getCell(coords).event()));
            } else if(field.getCell(coords).isPassable()){
                temp.push_back('-');
            } else{
                temp.push_back('=');
            }
        }
        result.push_back(temp);
    }
    result.push_back("hp: " + std::to_string(game_->health_points()) + "\nscore: " + std::to_string(game_->score()));
    view_->update(result);
}

char MapViewInitializer::eventToChar(EventInterface *event) {
    if(typeid(*event) == typeid(TrapEvent)) {
        return 't';
    } else if(typeid(*event) == typeid(TeleportEvent)) {
        return 'f';
    } else if(typeid(*event) == typeid(HealEvent)) {
        return 'h';
    } else {
        return 's';
    }
}

MapViewInitializer::~MapViewInitializer() noexcept {
    delete view_;
}