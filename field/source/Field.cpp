#include "../headers/Field.h"
#include <algorithm>

Field::Field() : Field(MIN_SIZE, MIN_SIZE) {}

Field::~Field() {
    clearField();
}

Field::Field(int x_size, int y_size) : Field(Point{x_size, y_size}){}

Field::Field(const Point& size) : start_({-1, -1}), finish_({-1, -1}), field_(nullptr), size_(size){
    createField(size);
}

Field::Field(const Field& other) : size_(other.size_), start_(other.start_), finish_(other.finish_), field_(nullptr) {
    createField(size_);
    for(int i = 0; i < size_.y; i++) {
        for(int j = 0; j < size_.x; j++) {
            field_[i][j] = other.field_[i][j];
        }
    }
}

void Field::swap(Field& other) {
    std::swap(field_, other.field_);
    std::swap(start_, other.start_);
    std::swap(finish_, other.finish_);
    std::swap(size_, other.size_);
}

Field &Field::operator= (const Field &other) {
    Field temp(other);
    clearField();
    swap(temp);
    return *this;
}

Field::Field(Field &&other) : size_({0,0}), start_({0,0}), finish_({0,0}), field_(nullptr)  {
    clearField();
    swap(other);
}

Field &Field::operator= (Field &&other) {
    if(&other != this) {
        clearField();
        swap(other);
    }
    return *this;
}
// написать swap, который будет вызываться в операторе и конструкторе, меняет поля местами (то же самое, что в операторе)

void Field::createField(const Point& size) {
    if(size.x > MAX_SIZE || size.x < MIN_SIZE || size.y > MAX_SIZE || size.y < MIN_SIZE) {
        throw std::invalid_argument("неверно заданы размеры поля");
    }

    field_ = new Cell* [size.y];
    for(int i = 0; i < size.y; i++) {
        field_[i] = new Cell[size.x];
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

bool Field::doesContainsCell(const Point& coordinates) const {
    return (coordinates.x >= 0 && coordinates.x < size_.x && coordinates.y >= 0 && coordinates.y < size_.y);
}

bool Field::isPassable(const Point& coordinates) {
    return doesContainsCell(coordinates) && field_[coordinates.y][coordinates.x].isPassable();
}

Cell& Field::getCell(const Point& coordinates) {
    if(!doesContainsCell(coordinates)) {
        throw std::out_of_range("there is no cell with such coordinates");
    }
    return field_[coordinates.y][coordinates.x];
}

void Field::setCell(const Point& coordinates, const Cell& cell) {
    if(!doesContainsCell(coordinates)) {
        field_[coordinates.y][coordinates.x] = cell;
    }
}

void Field::createWall(const Point &coordinates) {
    if(doesContainsCell(coordinates)) {
        field_[coordinates.y][coordinates.x].set_passablity(false);
    }
}

void Field::makePassable(const Point &coordinates) {
    if(!doesContainsCell(coordinates)) {
        field_[coordinates.y][coordinates.x].set_passablity(true);
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

int Field::set_start(const Point &coordinates) {
    if(doesContainsCell(coordinates) && field_[coordinates.y][coordinates.x].isPassable()) {
        start_ = coordinates;
        return 0;
    }
    return 1;
}

int Field::set_finish(const Point &coordinates) {
    if(doesContainsCell(coordinates) && field_[coordinates.y][coordinates.x].isPassable()) {
        finish_ = coordinates;
        return 0;
    }
    return 1;
}


// список дел: удалил гетер и сетер с rvalue, т.к. они кастятся к lvalue
// поменял celltype на true и false для проходимости, а старт и финиш хранятся в полях поля