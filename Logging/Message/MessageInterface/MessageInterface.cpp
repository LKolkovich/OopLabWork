#include "MessageInterface.h"


std::ostream &operator<<(std::ostream &out_str, MessageInterface &toOut) {
    toOut.toPrint(out_str);
    return out_str;
}