#include "FileStreamWrapper.h"
#include <fstream>

void FileStreamWrapper::toStream(MessageInterface &message) {
    std::ofstream out(LOGS_FILE_PATH, std::ios_base::app);
    if (out.is_open()) {
        out << message;
    } else {
        throw std::invalid_argument("can`t open logs file");
    }
    out.close();
}