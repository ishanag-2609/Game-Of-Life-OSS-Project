// GameMap.cpp
#include "GameMap.h"
#include <iostream>
GameMap::GameMap() {
// Fill the board with baseline safe tiles first
for (int i = 0; i <= 100; i++) {
board[i].position = i;
board[i].type = EMPTY;
board[i].description = "A quiet, peaceful path.";
}
board[0].type = START;
board[0].description = "The beginning of your life journey.";
board[100].type = FINISH;
board[100].description = "The Retirement Gate!";
}

void GameMap::generateMapLayout() {
// Distribute Career Blocks at fixed spaces (e.g., 5, 25, 55)
int careerSpots[] = {5, 25, 55};
for (int pos : careerSpots) {
board[pos].type = CAREER;
board[pos].description = "Career Milestone! Choose or upgrade occupations.";
}
// Distribute Real Estate House Blocks (e.g., 15, 45, 75)
int houseSpots[] = {15, 45, 75};
for (int pos : houseSpots) {
board[pos].type = HOUSE;
board[pos].description = "Real Estate Opportunity! Purchase property options.";
}
}