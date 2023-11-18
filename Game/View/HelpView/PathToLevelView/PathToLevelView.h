#ifndef CODE_PATHTOLEVELVIEW_H
#define CODE_PATHTOLEVELVIEW_H

#include "../../../GameContext/Game.h"
#include "../AbstractHelpView/AbstractHelpView.h"

class PathToLevelView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~PathToLevelView() override = default;
};


#endif //CODE_PATHTOLEVELVIEW_H
