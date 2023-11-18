#ifndef CODE_EVENTINTERFACE_H
#define CODE_EVENTINTERFACE_H

class PlayerController;

class EventInterface {
public:
    virtual EventInterface* execute(PlayerController &controller) = 0;
    virtual EventInterface* copy() const = 0;
    virtual ~EventInterface() = default;
};


#endif //CODE_EVENTINTERFACE_H
