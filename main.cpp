#include "player/headers/PlayerController.h"
#include <iostream>
#include "FieldBuilder/FieldBuilder.h"

void printMap(PlayerController &player_controller) {
    Field& field = player_controller.field();
    for(int i = 0; i < player_controller.field().size().y; i++) {
        for(int j = 0; j < player_controller.field().size().x; j++) {
            Point coords = {j, i};
            if(player_controller.get_coordinates() == coords) {
                std::cout << 'P';
            } else if(coords == field.start()) {
                std::cout << '!';
            } else if(coords == field.finish()) {
                std::cout << '?';
            } else if (field.getCell(coords).isEvent()) {
                std::cout << 'e';
            } else if(field.getCell(coords).isPassable()){
                std::cout << '-';
            } else{
                std::cout << '=';
            }
        }
        std::cout << '\n';
    }
    std::cout << "hp: " << player_controller.get_health_points() << "\nscore: " << player_controller.get_score() << '\n';
}

bool gameLoop(PlayerController player_controller) {
    Point finish = player_controller.field().finish();
    while(player_controller.get_coordinates() != finish) {
        system("cls");
        printMap( player_controller);
        if(player_controller.get_health_points() == 0){
            return false;
        }
        char direction;
        std::cin >> direction;

        switch (direction) {
            case 'w':
                player_controller.move(Sides::UP);
                break;
            case 's':
                player_controller.move(Sides::DOWN);
                break;
            case 'd':
                player_controller.move(Sides::RIGHT);
                break;
            case 'a':
                player_controller.move(Sides::LEFT);
                break;
        }
    }
    system("cls");
    printMap( player_controller);

    return true;
}

int main() {

    FieldBuilder fieldBuilder;
    Player player;
    Field field = fieldBuilder.createSecondLevel();
    PlayerController controller(player, field);
    bool doesWin =  gameLoop(controller);

    if(doesWin) {
        std::cout << "\n\n YOU WIN!!!\n\n";
    } else{
        std::cout << "\n\n YOU LOSE!!!\n\n";
    }
}
