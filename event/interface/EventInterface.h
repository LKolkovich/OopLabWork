#ifndef CODE_EVENTINTERFACE_H
#define CODE_EVENTINTERFACE_H

class PlayerController;

class EventInterface {
public:
    virtual void execute(PlayerController &controller) = 0;
    virtual EventInterface* copy() const = 0;
};

#endif //CODE_EVENTINTERFACE_H
