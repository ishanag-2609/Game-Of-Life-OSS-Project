// PaydayBlock.cpp
#include "PaydayBlock.h"
bool PaydayBlock::trigger(Player& p) {
    if (p.getSalary() > 0) {
        p.updateBalance(p.getSalary());
        return true;
    }
    return false;
}