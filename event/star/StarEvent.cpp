//
// Created by Leha Kolkovich on 24.10.2023.
//

#include "StarEvent.h"

StarEvent::StarEvent(int score) : score_(score) {}

void StarEvent::execute(PlayerController &controller) {
    if(!was_executed_) {
        controller.addScore(score_);
        was_executed_ = true;
    }
}

EventInterface* StarEvent::copy() const {
    return new StarEvent(score_);
}