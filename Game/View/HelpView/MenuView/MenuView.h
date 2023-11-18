#ifndef CODE_MENUVIEW_H
#define CODE_MENUVIEW_H

#include "../../../GameContext/Game.h"
#include "../../ViewInterface.h"
#include "../AbstractHelpView/AbstractHelpView.h"

class MenuView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~MenuView() override = default;
};


#endif //CODE_MENUVIEW_H
