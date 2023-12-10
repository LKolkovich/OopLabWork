#ifndef CODE_FILESETTINGSREADER_H
#define CODE_FILESETTINGSREADER_H

#include "../IFileSettingsReader.h"

#include <iostream>

class DefaultFileSettingsReader: public IFileSettingsReader{
public:
    void read(std::map<char, CommandsContainer::Commands> &keys, std::string path) override;
    ~DefaultFileSettingsReader() override = default;
};


#endif //CODE_FILESETTINGSREADER_H
