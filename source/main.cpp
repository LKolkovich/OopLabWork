#include "../headers/PlayerController.h"
#include <iostream>

int main(){
    Player *player;
    PlayerController player_controller = PlayerController(player);
    std::cout << player_controller.get_both_coordinates().first << ' ' << player_controller.get_both_coordinates().second << '\n';

    player_controller.Move(Sides::DOWN, 1);
    std::cout << player_controller.get_both_coordinates().first << ' ' << player_controller.get_both_coordinates().second << '\n';  

    player_controller.Move(Sides::RIGHT, 1);
    std::cout << player_controller.get_both_coordinates().first << ' ' << player_controller.get_both_coordinates().second << '\n';

    player_controller.Move(Sides::UP, 1);
    std::cout << player_controller.get_both_coordinates().first << ' ' << player_controller.get_both_coordinates().second << '\n';

    player_controller.Move(Sides::LEFT, 1);
    std::cout << player_controller.get_both_coordinates().first << ' ' << player_controller.get_both_coordinates().second << '\n';

}