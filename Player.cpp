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