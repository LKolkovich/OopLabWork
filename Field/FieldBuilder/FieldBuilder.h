#ifndef CODE_FIELDBUILDER_H
#define CODE_FIELDBUILDER_H

#define PATH_TO_LEVELS "levels/"

#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include "../Field/Field.h"

#include "../../Event/TrapEvent/TrapEvent.h"
#include "../../Event/HealEvent/HealEvent.h"
#include "../../Event/TeleportEvent/TeleportEvent.h"
#include "../../Event/StarEvent/StarEvent.h"

class FieldBuilder {
public:
    FieldBuilder();
    Field& createPremadeLevel(int level_num);
    Field& createLevelFromFile(const std::string &path);

private:
    Point size_;
    int trap_damage_;
    int heal_;
    int star_score_;
    std::vector<Point> teleport_destinations_;
    std::vector<std::string> readFile(const std::string &path);
    void createMap(Field& field, const std::vector<std::string> &map);
    void readInt(std::ifstream &file, int &value);
};


#endif //CODE_FIELDBUILDER_H
