#ifndef CODE_PICKLOGVIEW_H
#define CODE_PICKLOGVIEW_H

#include "../AbstractHelpView/AbstractHelpView.h"

class PickLogView : public AbstractHelpView {
public:
    void update(std::vector<std::string> &output) override;
    ~PickLogView() override = default;
};


#endif //CODE_PICKLOGVIEW_H
