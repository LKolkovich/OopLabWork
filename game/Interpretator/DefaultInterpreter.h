#ifndef CODE_INTERPRETATOR_H
#define CODE_INTERPRETATOR_H

#include "InterpreterInterface.h"

#include <map>

class DefaultInterpreter : public InterpreterInterface {
public:
    CommandsContainer::Commands toCommand(char symbol) const override;
    bool hasCommand(char symbol) const override;
    ~DefaultInterpreter() override = default;

};

#endif //CODE_INTERPRETATOR_H
