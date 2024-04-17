#ifndef CODE_STREAMWRAPPERINTERFACE_H
#define CODE_STREAMWRAPPERINTERFACE_H

#include "../../Message/MessageInterface/MessageInterface.h"

class StreamWrapperInterface {
public:
    virtual void toStream(MessageInterface &message) = 0;
    virtual ~StreamWrapperInterface() = default;
};

#endif //CODE_STREAMWRAPPERINTERFACE_H
