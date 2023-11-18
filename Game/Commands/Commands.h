#ifndef CODE_COMMANDS_H
#define CODE_COMMANDS_H

#include "../../Player/Sides/SIdes.h"

enum Commands {
    MOVE_UP = UP,
    MOVE_DOWN = DOWN,
    MOVE_LEFT = LEFT,
    MOVE_RIGHT = RIGHT,
    QUIT,
    START,
    SETTINGS,
    LAST // всегда последнее
};

#endif //CODE_COMMANDS_H
