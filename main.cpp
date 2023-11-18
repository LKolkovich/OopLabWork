#include "Player/PlayerController/PlayerController.h"
#include <iostream>
#include "Field/FieldBuilder/FieldBuilder.h"
#include "game/Reader/SettingsReader/FileSettingsReader/FileSettingsReader.h"
#include "game/Reader/SettingsReader/ConsoleSettingsReader/ConsoleSettingsReader.h"
#include "game/Interpretor/DefaultInterpreter.h"
#include "game/GameContext/Game.h"
#include "game/GameState/MenuState/MenuState.h"
#include "game/Reader/GameReader/GameReader.h"
//
//void printMap(PlayerController &player_controller) {
//    Field *field =  player_controller.field();
//    for(int i = 0; i < player_controller.field()->size().y; i++) {
//        for(int j = 0; j < player_controller.field()->size().x; j++) {
//            Point coords = {j, i};
//            if(player_controller.get_coordinates() == coords) {
//                std::cout << 'P';
//            } else if(coords == field->start()) {
//                std::cout << '!';
//            } else if(coords == field->finish()) {
//                std::cout << '?';
//            } else if (field->getCell(coords).isEvent()) {
//                std::cout << 'e';
//            } else if(field->getCell(coords).isPassable()){
//                std::cout << '-';
//            } else{
//                std::cout << '=';
//            }
//        }
//        std::cout << '\n';
//    }
//    std::cout << "hp: " << player_controller.get_health_points() << "\nscore: " << player_controller.get_score() << '\n';
//}
//
//
//
//void testDefaultConsoleSettingsReader(std::map<char, CommandsContainer::Commands> k) {
//    ConsoleSettingsReader reader;
//    //std::map<char, CommandsContainer::Commands> k;
//    reader.read();
//    std::cout << k.size() << '\n';
//    for (const auto &item: k) {
//        std::cout << item.first << ' ' << item.second << '\n';
//    }
//}
//
//void testDefaultFileSettingsReader() {
//    FileSettingsReader reader;
//    std::map<char, CommandsContainer::Commands> k;
//    reader.read();
//    std::cout << k.size() << '\n';
//    for (const auto &item: k) {
//        std::cout << item.first << ' ' << item.second << '\n';
//    }
//    testDefaultConsoleSettingsReader(k);
//}




int main() {
    Player player;
    PlayerController controller(player);
    GameReader *reader = new GameReader;
    Game game(controller, reader);
    game.start();
}
