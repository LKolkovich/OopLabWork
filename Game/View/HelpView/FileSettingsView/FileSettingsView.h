#ifndef CODE_FILESETTINGSVIEW_H
#define CODE_FILESETTINGSVIEW_H

#include "../../../GameContext/Game.h"
#include "../../ViewInterface.h"
#include "../AbstractHelpView/AbstractHelpView.h"

class FileSettingsView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~FileSettingsView() override = default;
};


#endif //CODE_FILESETTINGSVIEW_H
