#ifndef CODE_VIEWINTERFACE_H
#define CODE_VIEWINTERFACE_H

#include <string>
#include <vector>
#include <iostream>
#include "../Interpretor/DefaultInterpreter.h"
#include <sstream>

class ViewInterface {
public:
    virtual void update(std::vector<std::string> &output) = 0;
    virtual ~ViewInterface() = default;
};

#endif //CODE_VIEWINITIALIZERINTERFACE_H
