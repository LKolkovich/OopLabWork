#ifndef CODE_NEWGAMEMESSAGE_H
#define CODE_NEWGAMEMESSAGE_H

#include "../MessageInterface/MessageInterface.h"
#include "../../../../Field/Point/Point.h"

class NewGameMessage : public MessageInterface {
public:
    NewGameMessage(Point field_size, Point start_coordinates);
    ~NewGameMessage() override = default;
    void toPrint(std::ostream &out_str) const override;

private:
    Point field_size_;
    Point start_coordinates_;

};


#endif //CODE_NEWGAMEMESSAGE_H
