#ifndef TILE_H
#define TILE_H
#include <string>
// Explicit mapping of what kind of block a tile can be
enum TileType {
START,
EMPTY,
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
std::string description;
};
#endif