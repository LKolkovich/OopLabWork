#ifndef CODE_HEALEVENT_CPP
#define CODE_HEALEVENT_CPP

#include "HealEvent.h"

HealEvent::HealEvent(int health_score){
    if(health_score <= 0) {
        throw std::out_of_range("heal event health score be > 0");
    }
    health_score_ = health_score;
}

EventInterface* HealEvent::execute(PlayerController &controller) {
    controller.addHealthPoints(health_score_);
    delete this;
    return nullptr;
}

EventInterface* HealEvent::copy() const {
    return new HealEvent(health_score_);
}


#endif