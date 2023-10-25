#ifndef CODE_TRAPEVENT_H
#define CODE_TRAPEVENT_H

#include "../interface/EventInterface.h"
#include "../../player/headers/PlayerController.h"

class TrapEvent : public EventInterface{
private:
    int damage_;
    bool was_executed_;
public:
    TrapEvent(int damage);
    void execute(PlayerController &controller) override;
    EventInterface* copy() const override;
};


#endif //CODE_TRAPEVENT_H
