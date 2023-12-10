#ifndef CODE_TRAPEVENT_CPP
#define CODE_TRAPEVENT_CPP

#include "TrapEvent.h"

TrapEvent::TrapEvent(int damage){
    if(damage <= 0 || damage > 5) {
        throw std::out_of_range("trap event damage must be > 0 and <= 5");
    }
    damage_ = damage;
}

EventInterface* TrapEvent::execute(PlayerController &controller) {
    controller.addHealthPoints(-damage_);
    controller.addScore(- 2 * damage_);
    delete this;
    return nullptr;
}

EventInterface* TrapEvent::copy() const {
    return new TrapEvent(damage_);
}


#endif
