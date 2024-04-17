#ifndef CODE_OBSERVER_H
#define CODE_OBSERVER_H

#include "../Observable/Observable.h"
#include <vector>
#include "../../Logging/StreamWrapper/StreamWrapperInterface/StreamWrapperInterface.h"

class Observer {
public:
    virtual void check() = 0;
    virtual void addStream(StreamWrapperInterface* stream) = 0;
    void registerSubject(Observable* subject);
    void unregisterSubject(Observable* subject);
    virtual ~Observer() = default;

protected:
    std::vector<Observable*> subjects_;
};


#endif //CODE_OBSERVER_H
