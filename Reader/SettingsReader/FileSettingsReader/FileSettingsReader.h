#ifndef CODE_FILESETTINGSREADER_H
#define CODE_FILESETTINGSREADER_H

#include "../../interface/ReaderInterface.h"
#include "../../../Interpretor/AbstractInterpreter.h"

#include <iostream>
#include "../../AbstractReader/AbstractReader.h"

class FileSettingsReader: public AbstractReader {
public:
    FileSettingsReader();
    Commands read() override;
    void readOnStart(const std::string &path);
    ~FileSettingsReader() override = default;
};


#endif //CODE_FILESETTINGSREADER_H
