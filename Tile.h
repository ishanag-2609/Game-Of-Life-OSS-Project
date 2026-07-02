// Tile.h
#ifndef TILE_H
#define TILE_H
#include <string>
// Explicit mapping of what kind of block a tile can be
enum TileType {
START,
NORMAL,
CAREER,
PAYDAY,
HOUSE,
EVENT,
GAMBLE,
FINISH
};
struct Tile {
int position;
TileType type;
char symbol; // Character shown on the console map (S, ., C, P, H, $, G, F)
std::string label; // Short label used when printing tile info
};
#endif