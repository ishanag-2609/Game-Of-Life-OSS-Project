#include "Game.h"
#include "CareerBlock.h"
#include "HouseBlock.h"
#include "EventBlock.h"
#include "GambleTile.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Game::Game() : player("Player1")
{
    gameOver = false;
    currentTurn = 1;
    map.generateMapLayout();
}

void Game::run()
{
    initializeGame();
    std::srand((unsigned)std::time(0));

    while (!gameOver)
    {
        std::cout << "\n[ TURN " << currentTurn << " ]\n";
        std::cout << "Press Enter to roll dice...";
        std::cin.get();

        int dice = (std::rand() % 6) + 1;
        std::cout << "🎲 You rolled a " << dice << "!\n";
        player.movePlayer(dice);

        TileType t = map.getTileType(player.getPosition());
        switch (t)
        {
            case CAREER:  CareerBlock::trigger(player); break;
            case HOUSE:   HouseBlock::trigger(player);  break;
            case EVENT:   EventBlock::trigger(player);  break;
            case GAMBLE:  GambleTile::trigger(player);  break;
            case PAYDAY:  player.updateBalance(2000);   break; // simple salary credit
            default: break;
        }

        map.renderBoardProgress(player.getPosition());
        player.displayHUD();

        if (player.getBalance() <= 0)
        {
            gameOver = true;
            std::cout << "\n💀 You ran out of money. GAME OVER.\n";
            return; // skip the win screen
        }
        if (player.getPosition() >= 100)
        {
            gameOver = true;
        }

        currentTurn++;
    }
    checkWinLossConditions();
}

void Game::checkWinLossConditions()
{
    std::cout << "\n========================================\n";
    std::cout << "🏁 THE JOURNEY IS COMPLETE! 🏁\n";
    std::cout << "Final Balance: $" << player.getBalance() << "\n";
    std::cout << "========================================\n";
}
