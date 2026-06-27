// Player.h
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
private:
    std::string name;
    long balance;
    int currentPosition;
    std::string currentCareer;
    std::string ownedHouse;

public:
    Player(std::string playerName);
    std::string getName() const;
    long getBalance() const;
    int getPosition() const;
    std::string getCareer() const;
    std::string getHouse() const;
    void updateBalance(long amount);
    void movePlayer(int steps);
    void updateCareer(std::string newJob);
    void updateHouse(std::string newHouse);
    void displayHUD() const;
};
#endif