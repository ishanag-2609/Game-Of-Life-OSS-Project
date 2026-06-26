#include "Game.h"
#include <iostream>

Game::Game()
{
    gameOver = false;
    currentTurn = 1;
}

void Game::initializeGame()
{
    std::cout << "========================================\n";
    std::cout << "     GAME OF LIFE: 100 TILE EDITION     \n";
    std::cout << "========================================\n";
    std::cout << "Initializing game systems and assets...\n";
}

void Game::run()
{
    initializeGame();
    while (!gameOver)
    {
        std::cout << "\n[ TURN " << currentTurn << " ]\n";
        std::cout << "Press Enter to roll dice...";
        std::cin.get();
        currentTurn++;
        if (currentTurn > 5)
        {
            gameOver = true;
        }
    }
    checkWinLossConditions();
}

void Game::checkWinLossConditions()
{
    std::cout << "\n========================================\n";
    std::cout << "🏁 THE JOURNEY IS COMPLETE! 🏁\n";
    std::cout << "========================================\n";
}