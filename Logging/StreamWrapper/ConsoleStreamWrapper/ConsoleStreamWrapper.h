#ifndef CODE_CONSOLESTREAMWRAPPER_H
#define CODE_CONSOLESTREAMWRAPPER_H

#include "../StreamWrapperInterface/StreamWrapperInterface.h"

class ConsoleStreamWrapper : public StreamWrapperInterface {
public:
    void toStream(MessageInterface &message) override;
    ~ConsoleStreamWrapper() override = default;
};


#endif //CODE_CONSOLESTREAMWRAPPER_H
