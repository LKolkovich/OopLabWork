#ifndef CODE_SETTINGSREADER_H
#define CODE_SETTINGSREADER_H

#include "../../interface/ReaderInterface.h"
#include "../../../Interpretor/AbstractInterpreter.h"

#include <iostream>
#include "../../AbstractReader/AbstractReader.h"


class ConsoleSettingsReader : public AbstractReader{
public:
    ConsoleSettingsReader();
    Commands read() override;
    ~ConsoleSettingsReader() override = default;
};


#endif //CODE_SETTINGSREADER_H
