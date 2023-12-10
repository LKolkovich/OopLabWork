#ifndef CODE_IEVENT_H
#define CODE_IEVENT_H

class PlayerController;

class IEvent {
public:
    virtual void execute(PlayerController &controller) = 0;
    virtual IEvent* copy() const = 0;
};

#endif //CODE_IEVENT_H
