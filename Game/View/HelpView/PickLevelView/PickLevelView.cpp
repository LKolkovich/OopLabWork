#include "PickLevelView.h"

void PickLevelView::update(std::vector<std::string> &output) {
    std::cout << "----Pick Level____\n";

    char cmd;
    std::vector<std::string> commandsToFind;
    commandsToFind.push_back("UP");
    commandsToFind.push_back("DOWN");
    commandsToFind.push_back("QUIT");

    std::map<std::string, char> commands = findCommands(output, commandsToFind);

    std::cout << commands["UP"] << " - pick premade level\n";
    std::cout << commands["DOWN"] << " - input path to level file\n";
    std::cout << commands["QUIT"] << " - go back to main menu\n";
}