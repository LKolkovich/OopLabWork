#ifndef CODE_INTERPRETATOR_H
#define CODE_INTERPRETATOR_H

#include "AbstractInterpreter.h"


#include <map>

class DefaultInterpreter : public AbstractInterpreter {
public:
    Commands toCommand(char symbol) const override;
    bool hasCommand(char symbol) const override;
    char toChar(Commands cmd) override;
    ~DefaultInterpreter() override = default;
};

#endif //CODE_INTERPRETATOR_H
