#include "Game.h"
#include <iostream>

Game::Game(PlayerController &controller, ReaderInterface *reader) : controller_(controller), reader_(reader), view_initializer_(nullptr), isRunning_(false), current_state_(
        nullptr) {
    if(reader == nullptr) {
        throw std::invalid_argument("reader can`t be nullptr in Game constructor");
    }
    FileSettingsReader reader1;
    reader1.readOnStart("inp.txt");
    view_initializer_ = new SettingsViewInitializer(new DefaultInterpreter, new MenuView);
    goToState(new MenuState);
}

void Game::start() {
    if(reader_ == nullptr) {
        throw std::invalid_argument("reader can`t be nullptr when game starts");
    }

    if(view_initializer_ == nullptr) {
        throw std::invalid_argument("view initializer can`t be nullptr when game starts");
    }

    if(current_state_ == nullptr) {
        throw std::invalid_argument("state can`t be nullptr when game starts");
    }


    isRunning_ = true;
    view_initializer_->init();
    while (isRunning_) {
        Commands cmd = reader_->read();
        system("cls");
        current_state_->handle(cmd);
        view_initializer_->init();
    }
//много состояний, каждый из которых решает, что будет происходить сейчас в игре. тут один метод, который вызывает обработчик внутри состояния
//если надо выйти в главное меню - меняется состояние, но не разрушается цикл
}

// сделать winState и loseState. при переходе к ним view заменяется на winView или loseView
// выводится "input *start button* for go to main menu" После ввода этого символа переход к MenuState


void Game::goToState(AbstractState *new_state) {
    if(new_state == nullptr) {
        throw std::invalid_argument("state can`t be nullptr when it`s given to Game");
    }
    delete current_state_;
    current_state_ = new_state;
    current_state_->setGameContext(this);
}

void Game::pickPremadeLevel(int number) {
    FieldBuilder fieldBuilder;
    controller_.set_field(&fieldBuilder.createPremadeLevel(number));
    resetPlayer();
}

void Game::levelFromFile(const std::string &path) {
    FieldBuilder fieldBuilder;
    controller_.set_field(&fieldBuilder.createLevelFromFile(path));
    resetPlayer();
}

void Game::resetPlayer() {
    controller_.set_coordinates(controller_.field()->start());
    controller_.resetPlayer();
}

void Game::movePlayer(Sides direction) {
    controller_.move(direction);
}

void Game::quit() {
    isRunning_ = false;
}

bool Game::isLose() {
    return !controller_.doesAlive();
}

bool Game::isWin() {
    return controller_.field()->finish() == controller_.get_coordinates();
}

void Game::setReader(ReaderInterface *reader) {
    if(reader == nullptr) {
        throw std::invalid_argument("reader can`t be nullptr when it`s given to Game");
    }
    delete reader_;
    reader_ = reader;
}

void Game::set_view_initializer(ViewInitializerInterface *view_init) {
    if(view_init == nullptr) {
        throw std::invalid_argument("view can`t be nullptr when it`s given to Game");
    }
    delete view_initializer_;
    view_initializer_ = view_init;
}

Game::~Game() {
    delete reader_;
    delete current_state_;
    delete view_initializer_;
}

Field& Game::field() {
    return *controller_.field();
}

Point Game::playerPosition() {
    return controller_.get_coordinates();
}

int Game::score() {
    return controller_.get_score();
}

int Game::health_points() {
    return controller_.get_health_points();
}
