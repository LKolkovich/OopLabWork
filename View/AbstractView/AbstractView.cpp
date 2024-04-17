#include "AbstractView.h"

std::map<std::string, char> AbstractView::findCommands(const std::vector<std::string> &all, const std::vector<std::string> &cmds) {
    std::map<std::string, char> result;
    for(int i = 0; i < all.size(); i++) {
        std::stringstream ss(all[i]);
        char c;
        std::string command;
        ss >> command;
        ss >> c;
        if(contains(cmds, command)) {
            result.insert(std::pair<std::string, char>(command, c));
        }
    }
    return result;
}

bool AbstractView::contains(const std::vector<std::string> &arr, const std::string &key) {
    for(std::string str: arr) {
        if(str == key) {
            return true;
        }
    }
    return false;
}