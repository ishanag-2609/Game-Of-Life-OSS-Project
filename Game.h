#ifndef GAME_H
#define GAME_H

class Game
{
private:
    bool gameOver;
    int currentTurn;

public:
    Game();
    void initializeGame();
    void run();
    void checkWinLossConditions();
};

#endif