#ifndef CODE_FILESETTINGSSTATE_H
#define CODE_FILESETTINGSSTATE_H

#include "../MenuState/MenuState.h"

class InSettingsState : public AbstractState {
public:
    void handle(Commands cmd) override;
    ~InSettingsState() override = default;
};


#endif //CODE_FILESETTINGSSTATE_H
