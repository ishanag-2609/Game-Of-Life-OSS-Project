// EventBlock.cpp
#include "EventBlock.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
const std::string EventBlock::events[4] = {
    "Medical Emergency! Hospital bills require immediate compensation.",
    "Stock Market Windfall! Your investment assets experienced massive growth.",
    "Automobile Malfunction! Repair cost allocations deducted.",
    "Innocent Lottery Prize! Cash award credited directly to your profile."};
const long EventBlock::financialImpact[4] = {-2500, 5000, -1200, 3000};
void EventBlock::trigger(Player &p)
{
    // Seed random selection pool locally
    std::srand(std::time(0));
    int randomIndex = std::rand() % 4;
    std::cout << "\n⚡ === DYNAMIC LIFE INCIDENT === ⚡\n";
    std::cout << "Event: " << events[randomIndex] << "\n";
}
// Insert inside EventBlock::trigger right after message display
long delta = financialImpact[randomIndex];
p.updateBalance(delta);
std::cout << "=======================================\n";