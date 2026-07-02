// HouseBlock.h
#ifndef HOUSEBLOCK_H
#define HOUSEBLOCK_H
#include "Player.h"
#include <string>
class HouseBlock {
private:
    struct HouseOption { std::string name; long price; };
    static const HouseOption houses[6];
    static void display(int choice);
public:
    // Returns false if the player could not afford any house (game over condition)
    static bool trigger(Player& p);
};
#endif