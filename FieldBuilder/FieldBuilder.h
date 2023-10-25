#ifndef CODE_FIELDBUILDER_H
#define CODE_FIELDBUILDER_H

#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include "../field/headers/Field.h"

#include "../event/trap/TrapEvent.h"
#include "../event/heal/HealEvent.h"
#include "../event/teleport/TeleportEvent.h"
#include "../event/star/StarEvent.h"

class FieldBuilder {
public:
    FieldBuilder();
    Field& createFirstLevel();
    Field& createSecondLevel();
    Field& createLevelFromFile(std::string path);

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
