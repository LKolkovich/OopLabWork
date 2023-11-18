#include "PreMadeLevelView.h"

void PreMadeLevelView::update(std::vector<std::string> &output) {
    std::cout << "----Pick Level____\n";

    std::cout << "type number of level you want to load\n";
    std::cout << "all levels numbers: \n";
    for(const std::string &str : output) {
        std::cout << str << '\n';
    }
}