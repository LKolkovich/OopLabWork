#ifndef CODE_WINMESSAGE_H
#define CODE_WINMESSAGE_H

#include "../MessageInterface/MessageInterface.h"

class WinMessage : public MessageInterface {
public:
    WinMessage(int score, int health, int speed);
    ~WinMessage() override = default;
    void toPrint(std::ostream &out_str) const override;

private:
    int score_;
    int health_;
    int speed_;
};


#endif //CODE_WINMESSAGE_H
