#ifndef FIELD_BUILDER_CPP
#define FIELD_BUILDER_CPP

#include "FieldBuilder.h"
#include <sstream>


FieldBuilder::FieldBuilder() : size_(Point{0,0}), trap_damage_(0), heal_(0), star_score_(0) {};

Field &FieldBuilder::createPremadeLevel(int level_num) {
    if (level_num < 1) {
        throw std::invalid_argument("number of level in natural number");
    }

    std::string path = "levels/" + std::to_string(level_num) + ".txt";
    return createLevelFromFile(path);
}


Field& FieldBuilder::createLevelFromFile(const std::string &path) {
    std::vector<std::string> map = readFile(path);
    auto field = new Field (size_);
    createMap(*field, map);
    return *field;
}



void FieldBuilder::readInt(std::ifstream &file, int &value) {
    std::string tempStr;
    file >> tempStr;
    std::istringstream iss(tempStr);
    if(!(iss >> value)) {
        throw std::invalid_argument("wrong value in level file");
    }
}

std::vector<std::string> FieldBuilder::readFile(const std::string &path) {
    std::string tempStr;
    std::ifstream file;
    file.open(path);
    std::vector<std::string> map;
    if(file.is_open()) {
        int teleport_count;
        readInt(file, size_.x);
        readInt(file, size_.y);
        if(size_.x < MIN_SIZE || size_.y < MIN_SIZE || size_.x > MAX_SIZE || size_.y > MAX_SIZE) {
            throw std::out_of_range("wrong field size");
        }
        readInt(file, trap_damage_);
        readInt(file, heal_);
        readInt(file, star_score_);
        readInt(file, teleport_count);
        for (int i = 0; i < teleport_count; i++) {
            Point point;
            readInt(file, point.x);
            readInt(file, point.y);
            if(point.x >= size_.x || point.x < 0 || point.y >= size_.y || point.y < 0) {
                throw std::out_of_range("teleport destination out of field");
            }
            teleport_destinations_.push_back(point);
        }

        while(file >> tempStr) {
            map.push_back(tempStr);
        }
    } else {
        throw std::invalid_argument("no such level file or directory");
    }
    file.close();
    return map;
}

void FieldBuilder::createMap(Field &field, const std::vector<std::string> &map) {
    int teleport_number = 0;
    for(int i = 0; i < size_.y; i++) {
        for(int j = 0; j < size_.x; j++) {
            Point coords = {j, i};
            switch (map[i][j]) {
                case '-':
                    break;
                case '=':
                    field.createWall(coords);
                    break;
                case '!':
                    field.set_start(coords);
                    break;
                case '?':
                    field.set_finish(coords);
                    break;
                case 't':
                    field.getCell(coords).addEvent(new TrapEvent(trap_damage_));
                    break;
                case 'h':
                    field.getCell(coords).addEvent(new HealEvent(heal_));
                    break;
                case 's':
                    field.getCell(coords).addEvent(new StarEvent(star_score_));
                    break;
                case 'p':
                    field.getCell(coords).addEvent(new TeleportEvent(teleport_destinations_[teleport_number++]));
                    break;
                default:
                    throw std::invalid_argument("wrong symbol in the map");
            }
        }
    }
    if(field.finish() == Point{-1,-1}){
        throw std::invalid_argument("there is no finish in the map");
    }
    if(field.start() == Point{-1,-1}) {
        throw std::invalid_argument("there is no start in the map");
    }
}

#endif
