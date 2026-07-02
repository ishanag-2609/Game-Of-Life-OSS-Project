// CareerBlock.h
#ifndef CAREERBLOCK_H
#define CAREERBLOCK_H
#include "Player.h"
#include <string>
class CareerBlock {
private:
    static const std::string careers[6];
    static const long salaries[6];
    static void display(int dice);
public:
    static void trigger(Player& p);
};
#endif