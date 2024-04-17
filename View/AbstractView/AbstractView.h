#ifndef CODE_ABSTRACTVIEW_H
#define CODE_ABSTRACTVIEW_H

#include "../ViewInterface.h"

class AbstractView : public ViewInterface {
protected:
    std::map<std::string, char> findCommands(const std::vector<std::string> &all, const std::vector<std::string> &cmds);
private:
    bool contains(const std::vector<std::string> &arr, const std::string &key);
};


#endif //CODE_ABSTRACTVIEW_H
