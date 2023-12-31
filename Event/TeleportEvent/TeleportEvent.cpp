#ifndef CODE_TELEPORTEVENT_CPP
#define CODE_TELEPORTEVENT_CPP

#include "TeleportEvent.h"


TeleportEvent::TeleportEvent(Point destination) : destination_(destination) {}

TeleportEvent::TeleportEvent(int x, int y) : TeleportEvent(Point{x, y}) {}

EventInterface* TeleportEvent::execute(PlayerController &controller) {
    controller.set_coordinates(destination_);
    return this;
}

EventInterface* TeleportEvent::copy() const {
    return new TeleportEvent(destination_);
}
#endif
