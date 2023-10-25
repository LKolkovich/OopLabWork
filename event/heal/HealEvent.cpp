#ifndef CODE_HEALEVENT_CPP
#define CODE_HEALEVENT_CPP

#include "HealEvent.h"

HealEvent::HealEvent(int health_score) : health_score_(health_score), was_executed_(false){}

void HealEvent::execute(PlayerController &controller) {
    if(!was_executed_) {
        controller.addHealthPoints(health_score_);
        was_executed_ = true;
    }
}

EventInterface* HealEvent::copy() const {
    return new HealEvent(health_score_);
}

#endif