#include "ConsoleSettingsView.h"

void ConsoleSettingsView::update(std::vector<std::string> &output) {
    std::cout << "input key and name if command after it\n";
    std::cout << "now your settings is: \n";
    for(int i = 0; i < output.size(); i++) {
        std::stringstream ss(output[i]);
        char c;
        std::string command;
        ss >> command;
        ss >> c;
        std::cout << c << " - " << command << '\n';
    }

    std::vector<std::string> commandsToFind;
    commandsToFind.push_back("QUIT");

    std::map<std::string, char> commands = findCommands(output, commandsToFind);

    std::cout << '\n' << commands["QUIT"] << " - go back to settings menu\n";
}