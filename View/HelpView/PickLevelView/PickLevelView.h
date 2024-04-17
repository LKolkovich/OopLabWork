#ifndef CODE_PICKLEVELVIEW_H
#define CODE_PICKLEVELVIEW_H

#include "../AbstractHelpView/AbstractHelpView.h"

class PickLevelView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~PickLevelView() override = default;
};


#endif //CODE_PICKLEVELVIEW_H
