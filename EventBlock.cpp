// EventBlock.cpp
#include "EventBlock.h"
#include <iostream>
#include <cstdlib>
const std::string EventBlock::payEvents[30] = {
    "Your car had an accident!",
    "Medical emergency! Hospital bill.",
    "Your phone got stolen.",
    "Roof leak at home. Repair needed.",
    "You got a traffic fine.",
    "A bad business deal went wrong.",
    "Flood damaged your property.",
    "Your laptop crashed. Need a new one.",
    "Your bike broke down on the highway.",
    "Your wallet got lost in the market.",
    "Unexpected dental treatment needed.",
    "Your house power wiring short-circuited.",
    "Your pet needs urgent surgery.",
    "Your car tire burst and damaged the rim.",
    "Your air conditioner suddenly stopped working.",
    "A water pipe burst in your bathroom.",
    "You lost money in an online scam.",
    "Your fridge compressor failed.",
    "Your window glass shattered in a storm.",
    "Your luggage got lost during travel.",
    "Unexpected legal fees for a dispute.",
    "Your washing machine motor burned out.",
    "Your phone screen cracked badly.",
    "Your shop inventory got damaged.",
    "A tree fell and damaged your fence.",
    "Your internet router burned out.",
    "You misplaced an important document.",
    "Your scooter battery died suddenly.",
    "Your laptop got stolen from a park.",
    "Your parking ticket penalty increased."
};
const long EventBlock::payCost[30] = {
    5000, 8000, 3000, 4000, 1500, 6000, 7000, 2500, 3200, 1500,
    4500, 5200, 7800, 3900, 6500, 2700, 9000, 7200, 1800, 4100,
    8500, 5600, 2200, 6900, 3100, 1400, 800, 1600, 9300, 1200
};
const std::string EventBlock::winEvents[30] = {
    "You won the lottery!",
    "Stock market paid off!",
    "You found a wallet. Honest reward.",
    "Your YouTube channel went viral!",
    "Tax refund arrived.",
    "You sold old stuff online.",
    "Bonus from your company!",
    "Scratch card win!",
    "Your old investment matured.",
    "You won a small online giveaway.",
    "You got cashback from a payment app.",
    "Your landlord returned the security deposit.",
    "You earned money from selling photos online.",
    "You got a performance reward at work.",
    "You received unexpected royalty income.",
    "You found money in an old jacket pocket.",
    "Your side hustle made a profit.",
    "You received a scholarship reward.",
    "You got a referral bonus from a friend.",
    "You sold your old bike parts.",
    "Your blog post earned ad revenue.",
    "You won a local competition prize.",
    "You got a refund from a cancelled order.",
    "A friend returned money you lent earlier.",
    "You earned interest from your savings.",
    "You received a gift card reward.",
    "You received a surprise inheritance.",
    "Your startup idea got funded!",
    "You found treasure in a cave.",
    "You won a small gaming tournament prize!"
};
const long EventBlock::winAmount[30] = {
    20000, 12000, 3000, 8000, 5000, 2000, 10000, 15000, 4500, 6200,
    12000, 3500, 2100, 8000, 7000, 9200, 17500, 1500, 11000, 20000,
    5200, 4300, 6500, 16000, 3200, 5500, 2200, 24000, 100000, 13000
};
void EventBlock::trigger(Player& p) {
    int coin = std::rand() % 2;
    std::cout << "------------------------------------\n";
    std::cout << " EVENT TILE!\n";
    std::cout << "------------------------------------\n";
    if (coin == 0) {
        int idx = std::rand() % 30;
        std::cout << " BAD LUCK! " << payEvents[idx] << "\n";
        std::cout << " You pay : -$" << payCost[idx] << "\n";
        p.updateBalance(-payCost[idx]);
    } else {
        int idx = std::rand() % 30;
        std::cout << " GOOD LUCK! " << winEvents[idx] << "\n";
        std::cout << " You earn : +$" << winAmount[idx] << "\n";
        p.updateBalance(winAmount[idx]);
    }
    std::cout << " Money now : $" << p.getBalance() << "\n";
    std::cout << "------------------------------------\n";
    std::cout << "\n Press Enter to continue...";
    std::cin.get();
}