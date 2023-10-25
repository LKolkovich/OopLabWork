#ifndef CODE_TRAPEVENT_CPP
#define CODE_TRAPEVENT_CPP

#include "TrapEvent.h"

TrapEvent::TrapEvent(int damage) : damage_(damage), was_executed_(false) {}

void TrapEvent::execute(PlayerController &controller) {
    if(!was_executed_) {
        controller.addHealthPoints(-damage_);
        controller.addScore(- 2 * damage_);
        was_executed_ = true;
    }

}

EventInterface* TrapEvent::copy() const {
    return new TrapEvent(damage_);
}

#endif
