// CareerBlock.h
#ifndef CAREERBLOCK_H
#define CAREERBLOCK_H
#include "Player.h"
#include <string>
class CareerBlock {
private:
    static const std::string jobs[4];
    static const long salaries[4];
public:
    static void trigger(Player& p);
};
#endif