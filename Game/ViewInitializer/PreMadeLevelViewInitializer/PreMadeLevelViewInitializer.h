#ifndef CODE_PREMADELEVELVIEWINITIALIZER_H
#define CODE_PREMADELEVELVIEWINITIALIZER_H


#include "../ViewInitializerInterface.h"
#include "../../../Field/FieldBuilder/FieldBuilder.h"
#include "../../View/PreMadeLevelView/AbstractPreMadeLevelView/AbstractPreMadeLevelView.h"

#include <experimental/filesystem>
#include <filesystem>

class PreMadeLevelViewInitializer : public ViewInitializerInterface {
public:
    PreMadeLevelViewInitializer(AbstractPreMadeLevelView *view);
    void init() override;
    ~PreMadeLevelViewInitializer() override = default;
private:
    AbstractPreMadeLevelView *view_;

    void removeNotInteger(std::vector<std::string> &strings);
};

#endif //CODE_PREMADELEVELVIEWINITIALIZER_H
