#ifndef CODE_SETTINGSREADER_H
#define CODE_SETTINGSREADER_H

#include "../../interface/ReaderInterface.h"
#include "../../../Interpretor/AbstractInterpreter.h"

#include <iostream>

class ConsoleSettingsReader : public ReaderInterface{
public:
    Commands read() override;
    ~ConsoleSettingsReader() override = default;
};


#endif //CODE_SETTINGSREADER_H
