#include "Observer.h"

void Observer::registerSubject(Observable *subject) {
    for(Observable* obs : subjects_) {
        if(obs->id() == subject->id()) {
            return;
        }
    }
    subjects_.push_back(subject);
}

void Observer::unregisterSubject(Observable *subject) {
    for(auto iter = subjects_.begin(); iter != subjects_.end(); ++iter ) {
        if((*iter)->id() == subject->id()) {
            subjects_.erase( iter );
            return;
        }
    }
}
