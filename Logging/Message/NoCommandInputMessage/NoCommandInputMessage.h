#ifndef CODE_NOCOMMANDINPUTMESSAGE_H
#define CODE_NOCOMMANDINPUTMESSAGE_H

#include "../MessageInterface/MessageInterface.h"
#include "../../../../Field/Point/Point.h"

class NoCommandInputMessage : public MessageInterface {
public:
    NoCommandInputMessage(char input);
    ~NoCommandInputMessage() override = default;
    void toPrint(std::ostream &out_str) const override;

private:
    char input_;

};


#endif //CODE_NOCOMMANDINPUTMESSAGE_H
