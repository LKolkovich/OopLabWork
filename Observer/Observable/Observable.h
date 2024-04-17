#ifndef CODE_OBSERVABLE_H
#define CODE_OBSERVABLE_H

#include "../../Logging/Message/MessageInterface/MessageInterface.h"

class Observable {
public:
    MessageInterface* message();
    unsigned long long id() const;
    void removeMessage();

protected:
    MessageInterface* message_;
    static unsigned long long global_id;
    unsigned long long id_;
};

#endif //CODE_OBSERVABLE_H
