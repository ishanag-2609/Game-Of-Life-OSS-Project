// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(std::string playerName) {
    name = playerName;
    balance = 10000; // Starting baseline liquidity fund
    currentPosition = 0; // Starts at Tile 0 (Start)
    currentCareer = "Unemployed";
    ownedHouse = "None";
}

std::string Player::getName() const { return name; }
long Player::getBalance() const { return balance; }
int Player::getPosition() const { return currentPosition; }
std::string Player::getCareer() const { return currentCareer; }
std::string Player::getHouse() const { return ownedHouse; }

void Player::updateBalance(long amount) {
    balance += amount;
    std::cout << "Balance updated by: $" << amount << " | Total: $" << balance << "\n";
}

void Player::movePlayer(int steps) {
    currentPosition += steps;
    if (currentPosition > 100) {
        currentPosition = 100; // Cap at Retirement Gate boundary
    }
    std::cout << name << " moved " << steps << " steps forward to Tile: " << currentPosition << "/100\n";
}

void Player::updateCareer(std::string newJob) {
    currentCareer = newJob;
}

void Player::updateHouse(std::string newHouse) {
    ownedHouse = newHouse;
}

void Player::displayHUD() const {
    std::cout << "\n======================================\n";
    std::cout << "  PLAYER CONTROL PANEL: " << name << "\n";
    std::cout << "======================================\n";
    std::cout << "  Current Liquidity Wallet : $" << balance << "\n";
    std::cout << "  Job Title Specification  : " << currentCareer << "\n";
    std::cout << "  Real Estate Assets       : " << ownedHouse << "\n";
    std::cout << "  Matrix Grid Coordinates  : Tile " << currentPosition << "/100\n";
    std::cout << "======================================\n";
}