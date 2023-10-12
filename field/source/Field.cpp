//
// Created by Leha Kolkovich on 10.10.2023.
//

#include "../headers/Field.h"

Field::Field() : Field(MIN_SIZE, MIN_SIZE) {}

Field::~Field() {
    clearField();
}

Field::Field(int x_size, int y_size) : Field(Point{x_size, y_size}){}

Field::Field(const Point& size) : size_(size), start_({-1, -1}), finish_({-1, -1}), field_(nullptr){
    createField();
}

Field::Field(const Field& field) : size_(field.size_), start_(field.start_), finish_(field.finish_), field_(nullptr) {
    createField();
    for(int i = 0; i < size_.y; i++) {
        for(int j = 0; j < size_.x; j++) {
            field_[i][j] = field.field_[i][j];
        }
    }
}

Field &Field::operator= (const Field &other) {
    Field temp(other);
    clearField();
    std::swap(field_, temp.field_);
    std::swap(start_, temp.start_);
    std::swap(finish_, temp.finish_);
    std::swap(size_, temp.size_);
    return *this;
}

Field::Field(Field &&other) : size_({0,0}), start_({0,0}), finish_({0,0}), field_(nullptr)  {
    *this = std::move(other);
}

Field &Field::operator= (Field &&other) {
    if(&other != this) {
        clearField();
        std::swap(size_, other.size_);
        std::swap(start_, other.start_);
        std::swap(finish_, other.finish_);
        std::swap(field_, other.field_);
        other.field_ = nullptr;
    }
    return *this;
}

void Field::createField() {
    if(size_.x > MAX_SIZE || size_.x < MIN_SIZE || size_.y > MAX_SIZE || size_.y < MIN_SIZE) {
        throw std::invalid_argument("неверно заданы размеры поля");
    }

    field_ = new Cell* [size_.y];
    for(int i = 0; i < size_.y; i++) {
        field_[i] = new Cell[size_.x];
    }
}

void Field::clearField() {
    if(field_ == nullptr) {
        return;
    }

    for(int i = 0; i < size_.y; i++) {
        delete[] field_[i];
    }

    delete[] field_;
    field_ = nullptr;
}

bool Field::doesContainsPoint(const Point& coordinates) const {
    return (coordinates.x >= 0 && coordinates.x < size_.x && coordinates.y >= 0 && coordinates.y < size_.y);
}

bool Field::isPassable(const Point& coordinates) {
    return doesContainsPoint(coordinates) && getCell(coordinates).isPassable();
}

Cell& Field::getCell(const Point& coordinates) {
    if(!doesContainsPoint(coordinates)) {
        throw std::out_of_range("there is no cell with such coordinates");
    }
    return field_[coordinates.y][coordinates.x];
}

Cell& Field::getCell(Point&& coordinates) {
    if(!doesContainsPoint(coordinates)) {
        throw std::out_of_range("there is no cell with such coordinates");
    }
    return field_[coordinates.y][coordinates.x];
}

void Field::setCell(const Point &coordinates, Cell &&cell) {
    if(!doesContainsPoint(coordinates)) {
        field_[coordinates.y][coordinates.x] = cell;
    }
}

void Field::setCell(const Point& coordinates, const Cell& cell) {
    if(!doesContainsPoint(coordinates)) {
        field_[coordinates.y][coordinates.x] = cell;
    }
}

void Field::createWall(const Point &coordinates) {
    if(doesContainsPoint(coordinates)) {
        field_[coordinates.y][coordinates.x].set_type(CellType::UNPASSABLE);
    }
}

void Field::makePassable(const Point &coordinates) {
    if(!doesContainsPoint(coordinates)) {
        field_[coordinates.y][coordinates.x].set_type(CellType::PASSABLE);
    }
}

Point& Field::size() {
    return size_;
}

Point& Field::finish() {
    return finish_;
}

Point& Field::start() {
    return start_;
}

void Field::set_start(const Point &coordinates) {
    if(doesContainsPoint(coordinates) && field_[coordinates.y][coordinates.x].isPassable()) {
        start_ = coordinates;
        field_[coordinates.y][coordinates.x].set_type(CellType::START);
    }
}

void Field::set_finish(const Point &coordinates) {
    if(doesContainsPoint(coordinates) && field_[coordinates.y][coordinates.x].isPassable()) {
        finish_ = coordinates;
        field_[coordinates.y][coordinates.x].set_type(CellType::FINISH);
    }
}