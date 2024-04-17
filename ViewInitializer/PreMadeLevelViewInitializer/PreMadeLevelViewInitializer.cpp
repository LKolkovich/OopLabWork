#include "PreMadeLevelViewInitializer.h"


PreMadeLevelViewInitializer::PreMadeLevelViewInitializer(AbstractPreMadeLevelView *view) {
    if(view == nullptr)
        throw std::invalid_argument("view can`t be nullptr");
    view_ = view;
}

void PreMadeLevelViewInitializer::removeNotInteger(std::vector<std::string> &strings) {
    for(const std::string &str : strings) {
        if(str.find_first_not_of("0123456789") != std::string::npos) {
            strings.erase(std::remove(strings.begin(), strings.end(),str));
        }
    }
}

void PreMadeLevelViewInitializer::init() {
    std::string path = PATH_TO_LEVELS;
    std::vector<std::string> levels;
    for (const auto & entry :std::filesystem::directory_iterator(path)) {
        std::string file = entry.path().string();

        size_t lastSlash = file.find_last_of('/');

        std::string filename = file.substr(lastSlash + 1);

        size_t lastDot = filename.find_last_of('.');

        if (lastDot != std::string::npos) {
            filename = filename.substr(0, lastDot);
        }
        levels.push_back(filename);
    }
    std::sort(levels.begin(), levels.end());
    //removeNotInteger(levels);

    view_->update(levels);
}

