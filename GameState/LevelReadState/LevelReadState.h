#ifndef CODE_LEVELREADSTATE_H
#define CODE_LEVELREADSTATE_H

#include "../LevelPickState/LevelPickState.h"
#include "../../View/HelpView/PickLevelView/PickLevelView.h"

class LevelReadState : public AbstractState{
public:
    void handle(Commands cmd) override;
    ~LevelReadState() override = default;
};


#endif //CODE_LEVELREADSTATE_H
