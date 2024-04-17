#include "FileSettingsView.h"

void FileSettingsView::update(std::vector<std::string> &output) {

    std::cout << "input path to file with your settings\n";

    std::vector<std::string> commandsToFind;
    commandsToFind.push_back("QUIT");

    std::map<std::string, char> commands = findCommands(output, commandsToFind);

    std::cout << commands["QUIT"] << " - go to back settings menu\n";
}