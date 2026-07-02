// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(std::string playerName) {
    name = playerName;
    money = 15000;          // Starting money, as per the game design
    currentPosition = 0;    // Starts at tile 0 (START)
    currentCareer = "None";
    salary = 0;
    ownedHouse = "None";
    housePrice = 0;
}

std::string Player::getName() const { return name; }
long Player::getBalance() const { return money; }
int Player::getPosition() const { return currentPosition; }
std::string Player::getCareer() const { return currentCareer; }
long Player::getSalary() const { return salary; }
std::string Player::getHouse() const { return ownedHouse; }
long Player::getHousePrice() const { return housePrice; }

void Player::updateBalance(long amount) {
    money += amount;
}

void Player::setPosition(int pos) {
    currentPosition = pos;
}

void Player::movePlayer(int steps) {
    currentPosition += steps;
    if (currentPosition > 99) {
        currentPosition = 99; // Cap at Finish tile
    }
}

void Player::updateCareer(const std::string& newJob, long newSalary) {
    currentCareer = newJob;
    salary = newSalary;
}

void Player::updateHouse(const std::string& newHouse, long price) {
    ownedHouse = newHouse;
    housePrice = price;
}

void Player::showStatus(const std::string& tileLabel) const {
    std::cout << "\n====================================\n";
    std::cout << " INVENTORY / STATUS \n";
    std::cout << "====================================\n";
    std::cout << " Money       : $" << money << "\n";
    std::cout << " Tile        : " << currentPosition << "/99 (" << tileLabel << ")\n";
    std::cout << " Career      : " << currentCareer << "\n";
    std::cout << " Salary      : $" << salary << " per payday\n";
    std::cout << " House       : " << ownedHouse << "\n";
    std::cout << " House cost  : $" << housePrice << "\n";
    std::cout << "====================================\n";
}

void Player::displayHUD() const {
    std::cout << "\n===========\n";
    std::cout << " PLAYER CONTROL PANEL: " << name << "\n";
    std::cout << "===========\n";
    std::cout << " Money    : $" << money << "\n";
    std::cout << " Career   : " << currentCareer << "\n";
    std::cout << " House    : " << ownedHouse << "\n";
    std::cout << " Position : Tile " << currentPosition << "/99\n";
}