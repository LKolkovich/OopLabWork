#include "ConsoleStreamWrapper.h"

void ConsoleStreamWrapper::toStream(MessageInterface &message) {
    std::cout << message;
}