#include "../headers/PlayerController.h"
#include <iostream>
#include <cassert>

void testPlayer(Player &player) {
    int error_code;
    std::cout << "health points on start: " << player.health_points() << '\n';

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
    int error_code;

    std::cout << "player walked across the square\n";
    std::cout << player_controller.get_coordinates().first << ' ' << player_controller.get_coordinates().second << '\n';

    player_controller.move(Sides::DOWN);
    std::cout << player_controller.get_coordinates().first << ' ' << player_controller.get_coordinates().second << '\n';  

    player_controller.move(Sides::RIGHT);
    std::cout << player_controller.get_coordinates().first << ' ' << player_controller.get_coordinates().second << '\n';

    player_controller.move(Sides::UP);
    std::cout << player_controller.get_coordinates().first << ' ' << player_controller.get_coordinates().second << '\n';

    player_controller.move(Sides::LEFT);
    std::cout << player_controller.get_coordinates().first << ' ' << player_controller.get_coordinates().second << '\n';

    player_controller.add_health_points(10);
    std::cout << "\nafter add 10 hp nothing changed because player has full hp: " << player.health_points() << '\n' << 
        "method returns code " << error_code << "\n\n";

    player_controller.add_health_points(-2);
    std::cout << "player was careless and got damage so his hp decreased " << player.health_points() << '\n'<< 
        "method returns code " << error_code << "\n\n";

    player_controller.add_health_points(-20);
    std::cout << "Player got a lot of damage, so his hp is " << player.health_points() << '\n'<< 
        "method returns code " << error_code << "\n\n";

}


int main() {
    Player player;
    PlayerController player_controller = PlayerController(player);
    testPlayer(player);
    testPlayerController(player_controller, player);
}
