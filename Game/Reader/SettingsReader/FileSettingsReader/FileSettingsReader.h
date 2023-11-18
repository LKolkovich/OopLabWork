#ifndef CODE_FILESETTINGSREADER_H
#define CODE_FILESETTINGSREADER_H

#include "../../interface/ReaderInterface.h"
#include "../../../Interpretor/AbstractInterpreter.h"

#include <iostream>

class FileSettingsReader: public ReaderInterface {
public:
    Commands read() override;
    void readOnStart(const std::string &path);
    ~FileSettingsReader() override = default;
};


#endif //CODE_FILESETTINGSREADER_H
