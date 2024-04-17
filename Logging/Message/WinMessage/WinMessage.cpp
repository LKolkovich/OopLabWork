#include "WinMessage.h"


WinMessage::WinMessage(int score, int health, int speed) : score_(score), health_(health), speed_(speed) {}

void WinMessage::toPrint(std::ostream &out_str) const {
    out_str << "Player win: score=" << score_ << " | health_points=" << health_ << " | speed=" << speed_ << '\n';
}