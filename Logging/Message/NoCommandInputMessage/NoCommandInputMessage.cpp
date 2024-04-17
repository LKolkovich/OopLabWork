#include "NoCommandInputMessage.h"

NoCommandInputMessage::NoCommandInputMessage(char input) : input_(input) {}

void NoCommandInputMessage::toPrint(std::ostream &out_str) const {
    out_str << "Wrong input: input=" << input_ << '\n';
}
