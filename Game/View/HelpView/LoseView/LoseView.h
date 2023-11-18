#ifndef CODE_LOSEVIEW_H
#define CODE_LOSEVIEW_H

#include "../../../GameContext/Game.h"
#include "../AbstractHelpView/AbstractHelpView.h"

class LoseView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~LoseView() override = default;
};


#endif //CODE_LOSEVIEW_H
