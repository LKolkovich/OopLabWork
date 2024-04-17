#ifndef CODE_SETTINGSMENUVIEW_H
#define CODE_SETTINGSMENUVIEW_H

#include "../../../GameContext/Game.h"
#include "../../ViewInterface.h"
#include "../AbstractHelpView/AbstractHelpView.h"

class SettingsMenuView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~SettingsMenuView() override = default;
};

#endif //CODE_SETTINGSMENUVIEW_H
