#include "CommandInputMessage.h"

CommandInputMessage::CommandInputMessage(char input, Commands command) : input_(input), command_(command) {}

void CommandInputMessage::toPrint(std::ostream &out_str) const {
    out_str << "Command input: input=" << input_ << " | command=" << CommandsContainer::commandToStr(command_) << '\n';
}