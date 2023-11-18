#ifndef CODE_HEALEVENT_H
#define CODE_HEALEVENT_H

#include "../EventInterface/EventInterface.h"
#include "../../Player/PlayerController/PlayerController.h"

class HealEvent : public EventInterface {
public:
    HealEvent(int health_score);
    EventInterface* execute(PlayerController &controller) override;
    EventInterface* copy() const override;
    ~HealEvent() override = default;
private:
    int health_score_;
};


#endif //CODE_HEALEVENT_H
