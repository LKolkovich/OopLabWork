#ifndef CODE_PREMADELEVELVIEW_H
#define CODE_PREMADELEVELVIEW_H

#include "../../../game/GameContext/Game.h"
#include "AbstractPreMadeLevelView/AbstractPreMadeLevelView.h"

class PreMadeLevelView : public AbstractPreMadeLevelView {
public:
    void update(std::vector<std::string> &output) override;
    ~PreMadeLevelView() override = default;
};


#endif //CODE_PREMADELEVELVIEW_H
