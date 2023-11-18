#ifndef CODE_PATHLEVELREADER_H
#define CODE_PATHLEVELREADER_H

#include "../AbstractLevelReader/AbstractLevelReader.h"

class PathLevelReader : public AbstractLevelReader {
public:
    PathLevelReader(Game *game);
    Commands read() override;
    ~PathLevelReader() override = default;
};


#endif //CODE_PATHLEVELREADER_H
