// CareerBlock.cpp
#include "CareerBlock.h"
#include <iostream>
const std::string CareerBlock::jobs[4] = {
    "Software Engineer", "Data Analyst", "Medical Doctor", "Creative Artist"
};
const long CareerBlock::salaries[4] = {7000, 6000, 12000, 4500};

void CareerBlock::trigger(Player& p) {
    std::cout << "\n=== CAREER SELECTION MILESTONE ===\n";
    std::cout << "Select your professional specialization:\n";

    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << jobs[i]
                  << " (Salary: $" << salaries[i] << "/payday)\n";
    }

    int choice;
    std::cout << "Enter selection (1-4): ";
    std::cin >> choice;
}