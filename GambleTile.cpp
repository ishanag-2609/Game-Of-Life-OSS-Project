// GambleTile.cpp
#include "GambleTile.h"
#include <iostream>
#include <cstdlib>
#include <limits>
void GambleTile::trigger(Player& p) {
    char choice;
    std::cout << "------------------------------------\n";
    std::cout << " GAMBLE TILE\n";
    std::cout << "------------------------------------\n";
    std::cout << " Your Money : $" << p.getBalance() << "\n\n";
    std::cout << " Guess the dice & win 4x your bet!\n";
    std::cout << " Wrong guess = lose your bet.\n\n";
    std::cout << " Do you want to gamble? (Y/N): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (choice != 'Y' && choice != 'y') {
        std::cout << "\n You passed. Moving on!\n";
        std::cout << "\n Press Enter to continue...";
        std::cin.get();
        return;
    }
    long bet;
    std::cout << "\n Enter bet: $";
    std::cin >> bet;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (bet <= 0 || bet > p.getBalance()) {
        std::cout << "\n Invalid bet. Skipping gamble.\n";
        std::cout << "\n Press Enter to continue...";
        std::cin.get();
        return;
    }
    int guess;
    std::cout << " Pick a number (1-6): ";
    std::cin >> guess;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (guess < 1 || guess > 6) {
        std::cout << "\n Invalid number. Skipping gamble.\n";
        std::cout << "\n Press Enter to continue...";
        std::cin.get();
        return;
    }
    int dice = std::rand() % 6 + 1;
    std::cout << "\n Dice rolled : " << dice << "\n";
    if (dice == guess) {
        std::cout << " YOU WON! +$" << bet * 4 << "\n";
        p.updateBalance(bet * 4);
    } else {
        std::cout << " You lost! -$" << bet << "\n";
        p.updateBalance(-bet);
    }
    std::cout << " Money now : $" << p.getBalance() << "\n";
    std::cout << "------------------------------------\n";
    std::cout << "\n Press Enter to continue...";
    std::cin.get();
}