#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "GameMap.h"

class Game
{
private:
    bool gameOver;
    int currentTurn;
    Player player;
GameMap map;

public:
    Game();
    void initializeGame();
    void run();
    void checkWinLossConditions();
};

#endif

