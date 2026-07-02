// GameMap.h
#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "Tile.h"
#define TOTAL_TILES 100
class GameMap {
private:
Tile tiles[TOTAL_TILES]; // index 0 (Start) .. 99 (Finish)
public:
GameMap();
TileType getTileType(int position) const;

Tile getTile(int position) const;
void draw(int playerPos) const; // print the 10x10 map once
void redraw(int playerPos) const; // clear screen, then draw
};
#endif