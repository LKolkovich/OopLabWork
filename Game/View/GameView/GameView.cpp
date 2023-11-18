#include "GameView.h"


void GameView::update(std::vector<std::string> &output) {
    for(int i = 0; i < output.size(); i++) {
        std::cout << output[i];
        std::cout << '\n';
    }
}