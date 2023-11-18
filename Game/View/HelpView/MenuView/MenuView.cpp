#include "MenuView.h"

void MenuView::update(std::vector<std::string> &output) {
    std::cout << "----Welcome!----\n";

    std::vector<std::string> commandsToFind;
    commandsToFind.push_back("QUIT");
    commandsToFind.push_back("START");
    commandsToFind.push_back("SETTINGS");

    std::map<std::string, char> commandsForPrint = findCommands(output, commandsToFind);

    std::cout << commandsForPrint["START"] << " - START\n";
    std::cout << commandsForPrint["SETTINGS"] << " - SETTINGS\n";
    std::cout << commandsForPrint["QUIT"] << " - QUIT\n";

}