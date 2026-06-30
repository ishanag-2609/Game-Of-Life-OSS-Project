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

// Payday every 10 spaces starting from tile 10
for (int i = 10; i < 100; i += 10) {
board[i].type = PAYDAY;
board[i].description = "Payday! Collect your standard salary revenue.";
}
// Gamble spots (e.g., 35, 65, 85)
int gambleSpots[] = {35, 65, 85};
for (int pos : gambleSpots) {
board[pos].type = GAMBLE;
board[pos].description = "Casino Zone! Wager assets on probability rules.";
}
// Assign generic random life events to any remaining spots ending in 3 or 7
for (int i = 1; i < 100; i++) {
if (board[i].type == EMPTY && (i % 10 == 3 || i % 10 == 7)) {
board[i].type = EVENT;
board[i].description = "Dynamic Incident! Prepare for windfalls or
emergencies.";
}
}
}