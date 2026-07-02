// CareerBlock.cpp
#include "CareerBlock.h"
#include <iostream>
#include <cstdlib>
const std::string CareerBlock::careers[6] = {
    "Engineer", "Doctor", "Artist", "Business Owner", "Teacher", "Game Developer"
};
const long CareerBlock::salaries[6] = {3000, 5000, 2000, 6000, 2500, 4000};
void CareerBlock::display(int dice) {
    switch (dice) {
        case 1:
            std::cout << "Congratulations, you are now an Engineer!\n";
            std::cout << "You will be earning a solid $3000 salary building things that matter.\n";
            break;
        case 2:
            std::cout << "Congratulations, you are now a Doctor!\n";
            std::cout << "You will be earning $5000 while saving lives every single day.\n";
            break;
        case 3:
            std::cout << "Congratulations, you are now an Artist!\n";
            std::cout << "You will be earning $2000 doing what you truly love.\n";
            break;
        case 4:
            std::cout << "Congratulations, you are now a Business Owner!\n";
            std::cout << "You will be earning $6000 running your own show.\n";
            break;
        case 5:
            std::cout << "Congratulations, you are now a Teacher!\n";
            std::cout << "You will be earning $2500 shaping the next generation.\n";
            break;
        case 6:
            std::cout << "Congratulations, you are now a Game Developer!\n";
            std::cout << "You will be earning $4000 building games players will love.\n";
            break;
        default:
            break;
  }
}
void CareerBlock::trigger(Player& p) {
    std::cout << "------------------------------------\n";
    std::cout << " CAREER TILE!\n";
    std::cout << "------------------------------------\n";
    std::cout << " Roll the dice to get your career!\n\n";
    std::cout << " Dice  Career            Salary\n";
    std::cout << " ---------------------------------\n";
    for (int i = 0; i < 6; i++) {
        std::string name = careers[i];
        while ((int)name.length() < 18) name += " ";
        std::cout << " [" << i + 1 << "]  " << name << "$" << salaries[i] << "\n";
    }
    std::cout << "\n Press Enter to roll the dice...";
    std::cin.get();
    int dice = std::rand() % 6 + 1;
    p.updateCareer(careers[dice - 1], salaries[dice - 1]);
    std::cout << "------------------------------------\n";
    std::cout << " Dice rolled     : " << dice << "\n";
    std::cout << " Career assigned : " << p.getCareer() << "\n";
    std::cout << " Salary          : $" << p.getSalary() << " per payday\n";
    display(dice);
    std::cout << "------------------------------------\n";
    std::cout << "\n Press Enter to continue...";
    std::cin.get();
}

