// GambleTile.cpp
#include "GambleTile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
void GambleTile::trigger(Player &p)
{
    std::cout << "\n🎲 === CASINO GAMBLING ZONE === 🎲\n";
    std::cout << "Your total liquidity position: $" << p.getBalance() << "\n";
    std::cout << "Standard Wager Ticket Price: $2000\n";
    std::cout << "Would you like to play? (1 for Yes, 0 for No): ";
    int choice;
    std::cin >> choice;
}
// Insert inside GambleTile::trigger right after input choice
if (choice != 1)
{
    std::cout << "You opted out of the casino table games safely.\n";
    return;
}
if (p.getBalance() < 2000)
{
    std::cout << "❌ Access Denied: Insufficient capital available to purchase a 
                 ticket.\n ";
                 return;
}