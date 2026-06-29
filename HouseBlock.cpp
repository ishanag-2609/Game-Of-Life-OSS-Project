// HouseBlock.cpp
#include "HouseBlock.h"
#include <iostream>
const std::string HouseBlock::houses[3] = {"Suburban Condo", "Luxury Apartment", 
"Metropolitan Mansion"};
const long HouseBlock::costs[3] = {40000, 75000, 150000};

void HouseBlock::trigger(Player& p) {
    std::cout << "\n🏠 === REAL ESTATE INVESTMENTS === 🏠\n";
    std::cout << "Your current liquidity capital: $" << p.getBalance() << "\n";
    std::cout << "Available listings on the market:\n";

    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ". " << houses[i]
                  << " (Cost: $" << costs[i] << ")\n";
    }

    std::cout << "4. Pass (Do not invest in real estate right now)\n";

    int choice;
    std::cout << "Select a listing to purchase (1-4): ";
    std::cin >> choice;
}