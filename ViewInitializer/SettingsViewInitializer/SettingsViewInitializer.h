#ifndef CODE_SETTINGSVIEWINITIALIZER_H
#define CODE_SETTINGSVIEWINITIALIZER_H

#include "../ViewInitializerInterface.h"
#include "../../Interpretor/AbstractInterpreter.h"
#include "../../View/HelpView/AbstractHelpView/AbstractHelpView.h"

class SettingsViewInitializer : public ViewInitializerInterface {
public:
    SettingsViewInitializer(AbstractInterpreter *interpreter, AbstractHelpView *view);
    void init() override;
    ~SettingsViewInitializer() override;
private:
    AbstractInterpreter* interpreter_;
    AbstractHelpView* view_;
};


#endif //CODE_SETTINGSVIEWINITIALIZER_H
