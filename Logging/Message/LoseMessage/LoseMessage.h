#ifndef CODE_LOSEMESSAGE_H
#define CODE_LOSEMESSAGE_H

#include "../MessageInterface/MessageInterface.h"
#include "../../../../Field/Point/Point.h"

class LoseMessage : public MessageInterface {
public:
    LoseMessage(Point lose_coordinates);
    ~LoseMessage() override = default;
    void toPrint(std::ostream &out_str) const override;

private:
    Point lose_coordinates_;
};


#endif //CODE_LOSEMESSAGE_H
