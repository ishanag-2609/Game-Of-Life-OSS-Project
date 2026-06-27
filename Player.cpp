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