// EventBlock.h
#ifndef EVENTBLOCK_H
#define EVENTBLOCK_H
#include "Player.h"
#include <string>
class EventBlock {
private:
    static const std::string events[4];
    static const long financialImpact[4];
public:
    static void trigger(Player& p);
};
#endif