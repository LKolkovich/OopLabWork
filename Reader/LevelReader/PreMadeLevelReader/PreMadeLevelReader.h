#ifndef CODE_PREMADELEVELREADER_H
#define CODE_PREMADELEVELREADER_H

#include "../AbstractLevelReader/AbstractLevelReader.h"


class PreMadeLevelReader : public AbstractLevelReader {
public:
    PreMadeLevelReader(Game *game);
    Commands read() override;
    ~PreMadeLevelReader() override = default;
};



#endif //CODE_PREMADELEVELREADER_H
