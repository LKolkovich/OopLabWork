#include "player/headers/PlayerController.h"
#include <iostream>
#include "field/headers/Field.h"
#include <conio.h>

void testPlayer(Player &player) {
    int error_code;
    std::cout << "\nhealth points on start: " << player.health_points() << '\n';

    error_code = player.set_speed(10);
    std::cout << "player took powerUp so his speed increased: " << player.speed() << '\n'<<
              "set_speed returns code " << error_code << "\n\n";

    error_code = player.set_speed(-10);
    std::cout << "something went wrong and set_speed() got argument under 0, but speed would not change: " << player.speed() << '\n' <<
              "set_speed returns code " << error_code << "\n\n";

    error_code = player.set_speed(2);
    std::cout << "and finally his speed is " << player.speed() << "\n\n\n";

}

void testPlayerController(PlayerController player_controller, Player &player) {

    std::cout << "player walked across the square\n";
    std::cout << player_controller.get_coordinates().x << ' ' << player_controller.get_coordinates().y << '\n';

    player_controller.move(Sides::DOWN);
    std::cout << player_controller.get_coordinates().x << ' ' << player_controller.get_coordinates().y << '\n';

    player_controller.move(Sides::RIGHT);
    std::cout << player_controller.get_coordinates().x << ' ' << player_controller.get_coordinates().y << '\n';

    player_controller.move(Sides::UP);
    std::cout << player_controller.get_coordinates().x << ' ' << player_controller.get_coordinates().y << '\n';

    player_controller.move(Sides::LEFT);
    std::cout << player_controller.get_coordinates().x << ' ' << player_controller.get_coordinates().y << '\n';

    player_controller.add_health_points(10);
    std::cout << "\nafter add 10 hp nothing changed because player has full hp: " << player.health_points() << '\n' <<
              "does he alive? " << player_controller.doesAlive() << "\n\n";

    player_controller.add_health_points(-2);
    std::cout << "player was careless and got damage so his hp decreased " << player.health_points() << '\n'<<
              "does he alive? " << player_controller.doesAlive() << "\n\n";

    player_controller.add_health_points(-20);
    std::cout << "Player got a lot of damage, so his hp is " << player.health_points() << '\n'<<
              "does he alive? " << player_controller.doesAlive() << "\n\n";

}


int main() {
    Player player;
    player.set_speed(3);
    Field field(5,5);
    std::string map[5] = {"!----", "===--", "--=-=", "----=", "----?"};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            Point coords = {j, i};
            if(map[j][i] == '-') {
                field.makePassable(coords);
            } else if(map[j][i] == '=') {
                field.createWall(coords);
            } else if(map[j][i] == '!') {
                field.set_start(coords);
            } else {
                field.set_finish(coords);
            }
        }
    }

    PlayerController player_controller = PlayerController(player, field);
    Point finish = field.finish();

    while(player_controller.get_coordinates().x != finish.x || player_controller.get_coordinates().y != finish.y) {
        system("cls");
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                Point coords = {j, i};
                if(player_controller.get_coordinates().x == coords.x && player_controller.get_coordinates().y == coords.y) {
                    std::cout << 'P';
                } else if(field.getCell(coords).isStart()) {
                    std::cout << '!';
                } else if(field.getCell(coords).isFinish()) {
                    std::cout << '?';
                } else if(field.getCell(coords).isPassable()){
                    std::cout << '-';
                } else{
                    std::cout << '=';
                }
            }
            std::cout << '\n';
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

    std::cout << "\n\n YOU WIN!!!\n\n";
}
