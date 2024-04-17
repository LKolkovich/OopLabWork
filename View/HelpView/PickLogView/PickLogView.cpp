#include "PickLogView.h"

void PickLogView::update(std::vector<std::string> &output) {
    std::cout << "----Pick logs destination----\n";

    std::vector<std::string> commandsToFind;
    commandsToFind.push_back("UP");
    commandsToFind.push_back("DOWN");
    commandsToFind.push_back("LEFT");
    commandsToFind.push_back("QUIT");

    std::map<std::string, char> commands = findCommands(output, commandsToFind);

    std::cout << commands["UP"] << " - logs are output to console\n";
    std::cout << commands["DOWN"] << " - logs are output to file\n";
    std::cout << commands["LEFT"] << " - logs are output to console and file\n";
    std::cout << "every other key - no logs\n";
    std::cout << commands["QUIT"] << " - quit\n";
}
