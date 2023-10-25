#ifndef CODE_HEALEVENT_H
#define CODE_HEALEVENT_H

#include "../Interface/EventInterface.h"
#include "../../player/headers/PlayerController.h"

class HealEvent : public EventInterface {
private:
    int health_score_;
    bool was_executed_;
public:
    HealEvent(int health_score);
    void execute(PlayerController &controller) override;
    EventInterface* copy() const override;
};


#endif //CODE_HEALEVENT_H
