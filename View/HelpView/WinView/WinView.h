#ifndef CODE_WINVIEW_H
#define CODE_WINVIEW_H

#include "../../../GameContext/Game.h"
#include "../AbstractHelpView/AbstractHelpView.h"

class WinView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~WinView() override = default;
};


#endif //CODE_WINVIEW_H
