// EventBlock.h
#ifndef EVENTBLOCK_H
#define EVENTBLOCK_H
#include "Player.h"
#include <string>
class EventBlock {
private:
    static const std::string payEvents[30];
    static const long payCost[30];
    static const std::string winEvents[30];
    static const long winAmount[30];
public:
    static void trigger(Player& p);
};
#endif