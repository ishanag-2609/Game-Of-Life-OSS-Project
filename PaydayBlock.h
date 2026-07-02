// PaydayBlock.h
#ifndef PAYDAYBLOCK_H
#define PAYDAYBLOCK_H
#include "Player.h"
class PaydayBlock {
public:
    // Returns true if a salary was actually collected (player has a career)
    static bool trigger(Player& p);
};
#endif