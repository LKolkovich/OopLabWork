#include "SettingsViewInitializer.h"

SettingsViewInitializer::SettingsViewInitializer(AbstractInterpreter *interpreter, AbstractHelpView *view) : interpreter_(nullptr), view_(nullptr) {
    if(view == nullptr) {
        throw std::invalid_argument("view can`t be nullptr");
    }
    view_ = view;
    if(interpreter == nullptr) {
        throw std::invalid_argument("interpreter can`t be nullptr");
    }
    interpreter_ = interpreter;

}

void SettingsViewInitializer::init() {
    std::vector<std::string> result;
    std::unordered_map<std::string, Commands> map = CommandsContainer::strEqu;
    for (auto it = map.begin(); it != map.end(); it++) {
        result.push_back(it->first + ' ' + interpreter_->toChar(it->second));
    }
    view_->update(result);
}

SettingsViewInitializer::~SettingsViewInitializer() noexcept {
    delete interpreter_;
    delete view_;
}