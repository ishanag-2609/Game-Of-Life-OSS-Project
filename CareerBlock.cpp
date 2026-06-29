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

    // Insert inside CareerBlock::trigger right after selection input
    if (choice < 1 || choice > 4) {
        std::cout << "Standard placement assigned: Default Intern (Salary: $3000)\n";
        p.updateCareer("Default Intern");
    } else {
        std::cout << "🎉 Congratulations! You are now employed as a " << jobs[choice - 1] 
<< "!\n";
        p.updateCareer(jobs[choice - 1]);
    }
    std::cout << "=======================================\n";
}
 