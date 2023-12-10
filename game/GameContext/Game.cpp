#include "Game.h"

Game::Game(PlayerController &controller, AbstractReader &reader) : controller_(controller), reader_(reader) {}

void Game::start() {
    runMainMenu();
    runGameLoop();
}

void Game::runMainMenu() {
    
}

void Game::pickPremadeLevel(int number) {
    FieldBuilder fieldBuilder;
    controller_.set_field(fieldBuilder.createPremadeLevel(number));
}

void Game::levelFromFile(const std::string &path) {
    FieldBuilder fieldBuilder;
    controller_.set_field(fieldBuilder.createLevelFromFile(path));
}

void Game::runGameLoop() {
    Point finish = controller_.field().finish();
    while(controller_.get_coordinates() != finish) {
        if(controller_.get_health_points() == 0){
            std::cout << "you lose";
            break;
        }
        CommandsContainer::Commands command = reader_.read();
        if(command == CommandsContainer::QUIT) {
            break;
        } else if(command == CommandsContainer::MOVE_DOWN || command == CommandsContainer::MOVE_LEFT || command == CommandsContainer::MOVE_UP || command == CommandsContainer::MOVE_RIGHT) {
            controller_.move(static_cast<Sides>(command));
        }
    }
    system("cls");

}

void Game::movePlayer(Sides direction) {
    controller_.move(direction);
}

void Game::quit() {
    std::cout << "quit game";
}

void Game::restart() {
    std::cout << "restart game";
}


//МБ УДАЛИТЬ STATE