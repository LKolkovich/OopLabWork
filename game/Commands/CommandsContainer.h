#ifndef CODE_COMMANDSCONTAINER_H
#define CODE_COMMANDSCONTAINER_H

#include "../../player/headers/SIdes.h"

#include <vector>
#include <map>
#include <string>

class CommandsContainer {
public:
    enum Commands {
        MOVE_UP = UP,
        MOVE_DOWN = DOWN,
        MOVE_LEFT = LEFT,
        MOVE_RIGHT = RIGHT,
        QUIT,
        START,
        LAST // всегда последнее
    };
    static Commands strToCommand(std::string str);
    static std::vector<Commands> allCommands(); // используется чтобы получить массив значений перечисления без переписывания кода
    //то есть при любом изменении внутри перечисления с сохранением условия "LAST - последний элемент" всегда будет возвращаться полный список команд
    // возможно создать константную статик мапу где будут хранится данные о том какое строковое представление имеет каждая из команд (для удобства вывода)
private:
    static std::map<std::string, Commands> strEqu;
};


#endif //CODE_COMMANDSCONTAINER_H
