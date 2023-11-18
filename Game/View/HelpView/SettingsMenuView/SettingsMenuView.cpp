#include "SettingsMenuView.h"

void SettingsMenuView::update(std::vector<std::string> &output) {
    std::cout << "----SETTINGS----'\n";
    std::cout << "Pick source of new settings";

    std::vector<std::string> commandsToFind;
    commandsToFind.push_back("UP");
    commandsToFind.push_back("DOWN");
    commandsToFind.push_back("QUIT");

    std::map<std::string, char> commandsForPrint = findCommands(output, commandsToFind);

    std::cout << '\n' << commandsForPrint["UP"] << " - from console\n";
    std::cout << commandsForPrint["DOWN"] << " - from file\n";
    std::cout << commandsForPrint["QUIT"] << " - go to back menu\n";
}
