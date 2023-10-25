#ifndef CODE_STAREVENT_H
#define CODE_STAREVENT_H

#include "../interface/EventInterface.h"
#include "../../player/headers/PlayerController.h"


class StarEvent : public EventInterface {
private:
    int score_;
    bool was_executed_;
public:
    StarEvent(int score);
    void execute(PlayerController &controller) override;
    EventInterface* copy() const override;
};


#endif //CODE_STAREVENT_H
