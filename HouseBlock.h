#ifndef HOUSEBLOCK_H
#define HOUSEBLOCK_H

#include "Player.h"
#include <string>

class HouseBlock {
private:
    static const std::string houses[3];
    static const long costs[3];

public:
    static void trigger(Player& p);
};

#endif