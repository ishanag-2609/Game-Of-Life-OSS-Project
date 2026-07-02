// Game.cpp
#include "Game.h"
#include "CareerBlock.h"
#include "HouseBlock.h"
#include "EventBlock.h"
#include "GambleTile.h"
#include "PaydayBlock.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
// ---- local console helper (kept internal to this file) ---
static void cls() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
Game::Game() : player("Player1") {
}
void Game::showIntro() {
    cls();
    std::cout << "\n";
    std::cout << "**********************************************\n";
    std::cout << "*              GAME OF LIFE                   *\n";
    std::cout << "*             100 TILE EDITION                 *\n";
    std::cout << "**********************************************\n\n";
    std::cout << "STORY:\n";
    std::cout << "  Navigate 100 tiles of life! Get a career,\n";
    std::cout << "  collect salary at paydays, buy a house,\n";
    std::cout << "  survive random events, and reach FINISH!\n\n";
    std::cout << "TILE GUIDE:\n";
    std::cout << "  X = You     - Your current position on the map\n";
    std::cout << "  S = Start   - Where your journey begins\n";
    std::cout << "  F = Finish  - Reach here to WIN\n";
    std::cout << "  C = Career  - Roll dice, get assigned a career\n";
    std::cout << "  P = Payday  - Salary auto-collected as you pass\n";
    std::cout << "  H = House   - You must buy a house here\n";
    std::cout << "  G = Gamble  - Choose to bet or skip\n";
    std::cout << "  $ = Event   - Random fortune or misfortune\n";
    std::cout << "  . = Normal  - Nothing happens\n\n";
    std::cout << "NOTES:\n";
    std::cout << "  - Career and House tiles are forced stops\n";
    std::cout << "  - Event and Gamble tiles are non-forced stops\n";
    std::cout << "  - Payday is automatic as you pass through it\n";
    std::cout << "  - If you can't afford any house, the game ends\n\n";
    std::cout << "CONTROLS:\n";
    std::cout << "  Press Enter -> Roll dice and move\n";
    std::cout << "  Press M     -> View your status and inventory\n\n";
    std::cout << "STARTING MONEY: $15,000\n\n";
    std::cout << " Press Enter to begin...";
    std::cin.get();
    cls();
}
// Move step by step, handling Payday automatically while passing through.
// Stops immediately at forced tiles (Career, House, Finish).
// Returns true if a forced stop was hit.
bool Game::movePlayer(int dice) {
    for (int step = 0; step < dice; step++) {
        int pos = player.getPosition() + 1;
        player.setPosition(pos);
        if (player.getPosition() >= 99) {
            player.setPosition(99);
            return true; // reached Finish
        }
        TileType t = gmap.getTileType(player.getPosition());
        if (t == PAYDAY) {
            bool got = PaydayBlock::trigger(player);
            gmap.redraw(player.getPosition());
            std::cout << "------------------------------------\n";
            if (got) {
                std::cout << " PAYDAY! Salary +$" << player.getSalary()
<< " collected automatically!\n";
            } else {
                std::cout << " PAYDAY tile - no career yet, no salary.\n";
            }
            std::cout << " Money now : $" << player.getBalance() << "\n";
            std::cout << "------------------------------------\n";
            std::cout << "\n Press Enter to continue moving...";
            std::cin.get();
            continue;
        }
        if (t == CAREER || t == HOUSE || t == FINISH) {
            return true; // forced stop
        }
    }
    // Finished the full dice move without a forced stop.
    // Non-forced tiles (Event / Gamble) trigger only now.
    TileType finalTile = gmap.getTileType(player.getPosition());
    if (finalTile == EVENT) {
        gmap.redraw(player.getPosition());
        EventBlock::trigger(player);
    } else if (finalTile == GAMBLE) {
        gmap.redraw(player.getPosition());
        GambleTile::trigger(player);
    }
    return false;
}
// Handles a forced-stop tile. Returns false if the game should end here.
bool Game::handleTile() {
    TileType t = gmap.getTileType(player.getPosition());
    gmap.redraw(player.getPosition());
    if (t == CAREER) {
        CareerBlock::trigger(player);
    } else if (t == HOUSE) {
        bool bought = HouseBlock::trigger(player);
        if (!bought) return false; // couldn't afford any house -> game over
    }
    return true;
}
void Game::showWin() {
    gmap.redraw(player.getPosition());
    std::cout << "**********************************************\n";
    std::cout << "*                YOU WIN!!!                    *\n";
    std::cout << "**********************************************\n\n";
    std::cout << " Congratulations! You finished the Game of Life!\n\n";
    std::cout << " Final Money  : $" << player.getBalance() << "\n";
    std::cout << " Career       : " << player.getCareer() << "\n";
    std::cout << " House Owned  : " << player.getHouse() << "\n\n";
    long netWorth = player.getBalance() + player.getHousePrice();
    if (netWorth >= 200000) {
        std::cout << " Rating: TYCOON! You are legendary!\n";
    } else if (netWorth >= 100000) {
        std::cout << " Rating: MILLIONAIRE! Outstanding!\n";
    } else if (netWorth >= 75000) {
        std::cout << " Rating: WEALTHY! Great job!\n";
    } else if (netWorth >= 60000) {
        std::cout << " Rating: STABLE! Not bad at all!\n";
    } else if (netWorth >= 30000) {
        std::cout << " Rating: SURVIVED! Just barely!\n";
    } else {
        std::cout << " Rating: BROKE! Life was rough!\n";
    }
    std::cout << "\n Thanks for playing!\n";
    std::cout << "**********************************************\n";
}
void Game::showGameOver() {
    gmap.redraw(player.getPosition());
    std::cout << "**********************************************\n";
    std::cout << "*               GAME OVER!                     *\n";
    std::cout << "**********************************************\n\n";
    std::cout << " You ran out of money on tile " << player.getPosition() << ".\n";
    std::cout << " Career : " << player.getCareer() << "\n\n";
    std::cout << " Better luck next time!\n";
    std::cout << "**********************************************\n";
}
void Game::run() {
    std::srand((unsigned)std::time(0));
    showIntro();
    gmap.draw(player.getPosition());
    while (true) {
        if (player.getPosition() >= 99) {
            showWin();
            return;
        }
        std::cout << " Press Enter to roll (M = status): ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "m" || input == "M") {
            player.showStatus(gmap.getTile(player.getPosition()).label);
            std::cout << "\n Press Enter to continue...";
            std::cin.get();
            gmap.redraw(player.getPosition());
            continue;
        }
        int dice = std::rand() % 6 + 1;
        gmap.redraw(player.getPosition());
        std::cout << " You rolled: " << dice << "! Moving...\n";
        std::cout << " Press Enter to move...";
        std::cin.get();
        bool stoppedAtForced = movePlayer(dice);
        gmap.redraw(player.getPosition());
        if (stoppedAtForced && player.getPosition() < 99) {
            if (!handleTile()) {
                showGameOver();
                return;
            }
        }
        if (player.getBalance() <= 0) {
            showGameOver();
            return;
        }
        gmap.redraw(player.getPosition());
    }
}