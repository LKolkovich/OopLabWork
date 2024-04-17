#include "LoggingObserver.h"

void LoggingObserver::check() {
    for(auto subj : subjects_) {
        MessageInterface* msg = subj->message();
        for(auto s : streams_) {
            if(msg != nullptr) {
                s->toStream(*msg);
            }
        }
        subj->removeMessage();
    }
}

void LoggingObserver::addStream(StreamWrapperInterface* stream) {
    if(stream == nullptr) {
        throw std::invalid_argument("stream given to observer can`t be nullptr");
    }
    streams_.push_back(stream);
}

LoggingObserver::~LoggingObserver() {
    for(int i = 0; i < streams_.size(); i++) {
        delete streams_[i];
    }
}
