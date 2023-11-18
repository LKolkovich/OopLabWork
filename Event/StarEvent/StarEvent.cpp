#ifndef STAR_EVENT_CPP
#define STAR_EVENT_CPP

#include "StarEvent.h"

StarEvent::StarEvent(int score){
    if(score <= 0) {
        throw std::out_of_range("StarEvent Event score must be > 0");
    }
    score_ = score;
}

EventInterface* StarEvent::execute(PlayerController &controller) {
    controller.addScore(score_);
    delete this;
    return nullptr;
}

EventInterface* StarEvent::copy() const {
    return new StarEvent(score_);
}

#endif