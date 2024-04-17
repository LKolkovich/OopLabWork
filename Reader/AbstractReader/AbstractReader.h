#ifndef CODE_ABSTRACTREADER_H
#define CODE_ABSTRACTREADER_H

#include "../interface/ReaderInterface.h"
#include "../../Logging/Message/NoCommandInputMessage/NoCommandInputMessage.h"
#include "../../Logging/Message/CommandInputMessage/CommandInputMessage.h"

class AbstractReader : public ReaderInterface {
public:
    void makeCommandMessage(char symbol, Commands command);
    void makeNoCommandMessage(char symbol);
    virtual ~AbstractReader() = default;
};


#endif //CODE_ABSTRACTREADER_H
