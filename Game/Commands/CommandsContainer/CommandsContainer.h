#ifndef CODE_COMMANDSCONTAINER_H
#define CODE_COMMANDSCONTAINER_H

#include "../../../Player/Sides/SIdes.h"

#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include "../Commands.h"

class CommandsContainer {
public:
    static const std::unordered_map<std::string, Commands> strEqu;
    static Commands strToCommand(std::string str);

    static std::vector<Commands> allCommands(); // используется чтобы получить массив значений перечисления без переписывания кода
    //то есть при любом изменении внутри перечисления с сохранением условия "LAST - последний элемент" всегда будет возвращаться полный список команд

};


#endif //CODE_COMMANDSCONTAINER_H
