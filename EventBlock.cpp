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