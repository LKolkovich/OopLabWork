#ifndef CODE_CONSOLESETTINGSVIEW_H
#define CODE_CONSOLESETTINGSVIEW_H

#include "../../../GameContext/Game.h"
#include "../AbstractHelpView/AbstractHelpView.h"

class ConsoleSettingsView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~ConsoleSettingsView() override = default;
};


#endif //CODE_CONSOLESETTINGSVIEW_H
