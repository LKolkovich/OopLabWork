#ifndef CODE_COMMANDINPUTMESSAGE_H
#define CODE_COMMANDINPUTMESSAGE_H

#include "../MessageInterface/MessageInterface.h"
#include "../../../Commands/CommandsContainer/CommandsContainer.h"

class CommandInputMessage : public MessageInterface {
public:
    CommandInputMessage(char input, Commands command);
    ~CommandInputMessage() override = default;
    void toPrint(std::ostream &out_str) const override;

private:
    char input_;
    Commands command_;
};


#endif //CODE_COMMANDINPUTMESSAGE_H
