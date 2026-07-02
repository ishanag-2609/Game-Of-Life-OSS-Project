// HouseBlock.cpp
#include "HouseBlock.h"
#include <iostream>
#include <limits>
const HouseBlock::HouseOption HouseBlock::houses[6] = {
    {"Studio Apartment",  25000},
    {"1BHK Flat",         45000},
    {"2BHK Apartment",    70000},
    {"3BHK Apartment",    95000},
    {"Suburban Villa",   150000},
    {"Luxury Penthouse", 250000}
};
void HouseBlock::display(int choice) {
    switch (choice) {
 case 1: std::cout << "Congratulations on owning your very own studio apartment!\n"; break;
        case 2: std::cout << "Congratulations on your 1BHK flat, a smart investment!\n"; break;
        case 3: std::cout << "Congratulations on your spacious 2BHK apartment!\n"; break;
        case 4: std::cout << "Congratulations on your magnificent 3BHK apartment!\n"; break;
        case 5: std::cout << "Congratulations on your stunning suburban villa!\n"; break;
        case 6: std::cout << "Congratulations on your magnificent luxury penthouse!\n"; break;
        default: break;
    }
}
bool HouseBlock::trigger(Player& p) {
    std::cout << "------------------------------------\n";
    std::cout << " HOUSE TILE!\n";
    std::cout << "------------------------------------\n";
    std::cout << " Your Money: $" << p.getBalance() << "\n\n";
    bool canAffordAny = false;
    for (int i = 0; i < 6; i++) {
        if (p.getBalance() >= houses[i].price) { canAffordAny = true; break; }
    }
    std::cout << " #   House                Price      Status\n";
    std::cout << " ---------------------------------------------------\n";
    for (int i = 0; i < 6; i++) {
        std::string name = houses[i].name;
        while ((int)name.length() < 20) name += " ";
        std::cout << " [" << i + 1 << "] " << name << " $" << houses[i].price;
        std::cout << (p.getBalance() >= houses[i].price ? " [CAN BUY]" : " [too expensive]");
        std::cout << "\n";
    }
    if (!canAffordAny) {
        std::cout << "\n------------------------------------\n";
        std::cout << " You couldn't save enough for a house. GAME OVER!\n";
        std::cout << "------------------------------------\n";
        return false;
    }
    int choice = 0;
    while (true) {
        std::cout << "\n Choose a house (1-6): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice < 1 || choice > 6) {
            std::cout << " Invalid choice. Try again.\n";
            continue;
        }
        if (p.getBalance() < houses[choice - 1].price) {
            std::cout << " You cannot afford that! Choose another.\n";
            continue;
        }
        break;
    }
    p.updateBalance(-houses[choice - 1].price);
    p.updateHouse(houses[choice - 1].name, houses[choice - 1].price);
    std::cout << "------------------------------------\n";
    std::cout << " You bought: " << houses[choice - 1].name << "!\n";
    std::cout << " Money left: $" << p.getBalance() << "\n";
    display(choice);
    std::cout << "------------------------------------\n";
    std::cout << "\n Press Enter to continue...";
    std::cin.get();
    return true;
}