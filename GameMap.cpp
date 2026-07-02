// GameMap.cpp
#include "GameMap.h"
#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
// ---- local console helpers (kept internal to this file) ----
static void cls() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}
GameMap::GameMap() {
// 1. Fill every tile with a safe default (NORMAL)
for (int i = 0; i < TOTAL_TILES; i++) {
tiles[i].position = i;
tiles[i].type = NORMAL;
tiles[i].symbol = '.';
tiles[i].label = "NORMAL";
}
// 2. Start / Finish
tiles[0] = Tile{0, START, 'S', "START"};
tiles[TOTAL_TILES - 1] = Tile{TOTAL_TILES - 1, FINISH, 'F', "FINISH"};
// 3. Career tile (forced stop)
tiles[20] = Tile{20, CAREER, 'C', "CAREER"};
// 4. House tile (forced stop)
tiles[55] = Tile{55, HOUSE, 'H', "HOUSE"};
// 5. Payday tiles (auto-collect while passing through)
int paydaySpots[] = {10, 25, 36, 43, 51, 61, 71, 81, 90, 98};
for (int pos : paydaySpots) {
tiles[pos] = Tile{pos, PAYDAY, 'P', "PAYDAY"};
}
// 6. Gamble tiles (non-forced stop)
int gambleSpots[] = {15, 31, 38, 44, 60, 64, 73, 75, 86, 92};
for (int pos : gambleSpots) {
tiles[pos] = Tile{pos, GAMBLE, 'G', "GAMBLE"};
}
// 7. Event tiles (non-forced stop)
int eventSpots[] = {2, 4, 6, 7, 8, 9, 11, 13, 16, 18, 22, 24, 27, 29,
33, 35, 37, 42, 46, 50, 52, 57, 63, 66, 70, 72,
78, 84, 88, 93, 95, 97};
for (int pos : eventSpots) {
// Don't overwrite a tile that already has a special assignment
if (tiles[pos].type == NORMAL) {
tiles[pos] = Tile{pos, EVENT, '$', "EVENT"};
}
}
}
TileType GameMap::getTileType(int position) const {
if (position < 0 || position >= TOTAL_TILES) return NORMAL;
return tiles[position].type;
}

Tile GameMap::getTile(int position) const {
if (position < 0 || position >= TOTAL_TILES) return tiles[0];
return tiles[position];
}
void GameMap::draw(int playerPos) const {
std::string border = "+----------------------------------------+";
std::cout << "\n GAME OF LIFE - 100 TILE MAP\n";
std::cout << " " << border << "\n";
for (int row = 0; row < 10; row++) {
int start, end, step;
// Boustrophedon (snake) layout, same rows as the original console map
if (row % 2 == 0) { start = row * 10; end = row * 10 + 9; step = 1; }
else { start = row * 10 + 9; end = row * 10; step = -1; }
std::cout << " |";
for (int t = start; step > 0 ? t <= end : t >= end; t += step) {
if (t == playerPos) std::cout << " X |";
else std::cout << " " << tiles[t].symbol << " |";
}
std::cout << "\n";
}
std::cout << " " << border << "\n\n";
}
void GameMap::redraw(int playerPos) const {
cls();
draw(playerPos);
}