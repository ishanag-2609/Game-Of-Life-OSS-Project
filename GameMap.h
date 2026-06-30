#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "Tile.h"
class GameMap {
private:
Tile board[101]; // 0 (Start) to 100 (Finish)
public:
GameMap();
void generateMapLayout();
TileType getTileType(int position) const;
void renderBoardProgress(int playerPosition) const;
};
#endif