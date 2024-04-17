#ifndef CODE_FILESTREAMWRAPPER_H
#define CODE_FILESTREAMWRAPPER_H

//#define LOGS_FILE_PATH "../logs/logs.txt"
#define LOGS_FILE_PATH "logs/logs.txt"

#include "../StreamWrapperInterface/StreamWrapperInterface.h"

class FileStreamWrapper : public StreamWrapperInterface {
public:
    void toStream(MessageInterface &message) override;
    ~FileStreamWrapper() override = default;

};


#endif //CODE_FILESTREAMWRAPPER_H
