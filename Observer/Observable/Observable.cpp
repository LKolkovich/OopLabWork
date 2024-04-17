#include "Observable.h"


unsigned long long Observable::id() const {
    return id_;
}

MessageInterface *Observable::message() {
    return message_;
}

void Observable::removeMessage() {
    if(message_ != nullptr) {
        delete message_;
        message_ = nullptr;
    }
}

unsigned long long Observable::global_id = 0;