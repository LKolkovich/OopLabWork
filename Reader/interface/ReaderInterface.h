#ifndef CODE_IREADER_H
#define CODE_IREADER_H

#include "../../Commands/CommandsContainer/CommandsContainer.h"
#include <string>
#include "../../Observer/Observable/Observable.h"

class Game;

class ReaderInterface : public Observable {
public:
    virtual Commands read() = 0;
    virtual ~ReaderInterface() = default;
};
//написать нечувстительное сравнкение, потом использовать его во всех трех считываниях
#endif //CODE_IREADER_H
