#ifndef CODE_IREADER_H
#define CODE_IREADER_H

#include "../../Commands/CommandsContainer.h"
#include <string>

class Game;

class AbstractReader {
public:
    virtual CommandsContainer::Commands read() = 0;
    virtual ~AbstractReader() = default;
};
//написать нечувстительное сравнкение, потом использовать его во всех трех считываниях
#endif //CODE_IREADER_H
