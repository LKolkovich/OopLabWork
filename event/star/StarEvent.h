#ifndef CODE_STAREVENT_H
#define CODE_STAREVENT_H

#include "../interface/EventInterface.h"
#include "../../player/headers/PlayerController.h"


class StarEvent : public EventInterface {
public:
    StarEvent(int score);
    EventInterface* execute(PlayerController &controller) override;
    EventInterface* copy() const override;
    ~StarEvent() override = default;
private:
    int score_;
};


#endif //CODE_STAREVENT_H
