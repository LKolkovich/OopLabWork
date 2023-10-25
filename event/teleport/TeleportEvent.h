#ifndef CODE_TELEPORTEVENT_H
#define CODE_TELEPORTEVENT_H

#include "../interface/EventInterface.h"
#include "../../player/headers/PlayerController.h"

class TeleportEvent : public EventInterface{
private:
    Point destination_;
public:
    TeleportEvent(Point destination);
    TeleportEvent(int x, int y);
    void execute(PlayerController &controller) override;
    EventInterface* copy() const override;
};


#endif //CODE_TELEPORTEVENT_H
