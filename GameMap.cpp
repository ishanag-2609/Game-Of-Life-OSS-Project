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