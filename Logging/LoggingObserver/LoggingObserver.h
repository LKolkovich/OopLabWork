#ifndef CODE_LOGGINGOBSERVER_H
#define CODE_LOGGINGOBSERVER_H

#include "../../Observer/Observer/Observer.h"

class LoggingObserver : public Observer {
public:
    void check() override;
    void addStream(StreamWrapperInterface* stream) override;
    ~LoggingObserver() override;

private:
    std::vector<StreamWrapperInterface*> streams_;
};


#endif //CODE_LOGGINGOBSERVER_H
