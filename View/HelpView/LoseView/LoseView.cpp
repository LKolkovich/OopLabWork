#include "LoseView.h"

void LoseView::update(std::vector<std::string> &output) {
    std::cout << "---!YOU LOSE!---\n";
    std::cout << "----IT`S SAD----\n";

    std::vector<std::string> commandsToFind;
    commandsToFind.push_back("QUIT");

    std::map<std::string, char> commandsForPrint = findCommands(output, commandsToFind);


    std::cout << '\n' << commandsForPrint["QUIT"] << " - go to back menu\n";
}