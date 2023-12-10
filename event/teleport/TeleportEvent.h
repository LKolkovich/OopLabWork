#ifndef CODE_TELEPORTEVENT_H
#define CODE_TELEPORTEVENT_H

#include "../interface/EventInterface.h"
#include "../../player/headers/PlayerController.h"

class TeleportEvent : public EventInterface{
public:
    TeleportEvent(Point destination);
    TeleportEvent(int x, int y);
    EventInterface* execute(PlayerController &controller) override;
    EventInterface* copy() const override;
    ~TeleportEvent() override = default;
private:
    Point destination_;
};


#endif //CODE_TELEPORTEVENT_H
