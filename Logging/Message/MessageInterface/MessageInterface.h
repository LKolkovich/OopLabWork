#ifndef CODE_MESSAGEINTERFACE_H
#define CODE_MESSAGEINTERFACE_H

#include <streambuf>
#include <iostream>

class MessageInterface {
public:
    virtual ~MessageInterface() = default;
    virtual void toPrint(std::ostream &out_str) const = 0;
    friend std::ostream &operator<<(std::ostream &out_str, MessageInterface &toOut);
};


#endif //CODE_MESSAGEINTERFACE_H
