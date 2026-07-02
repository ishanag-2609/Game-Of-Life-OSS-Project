#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "GameMap.h"
class Game {
private:
    Player player;
    GameMap gmap;
    void showIntro();
    void showWin();
    void showGameOver();
    // Moves the player step by step; returns true if movement stopped
    // early at a forced tile (Career, House, Finish).
    bool movePlayer(int dice);
    // Dispatches to the correct forced-tile handler (Career / House).
    // Returns false if handling the tile ended the game (e.g. couldn't
    // afford any house).
    bool handleTile();
public:
    Game();
    void run();
};
#endif