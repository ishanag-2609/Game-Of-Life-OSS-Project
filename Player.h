// Player.h
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
private:
    std::string name;
    long money;
    int currentPosition;
    std::string currentCareer;
    long salary;
    std::string ownedHouse;
    long housePrice;

public:
    Player(std::string playerName = "Player1");

    // getters
    std::string getName() const;
    long getBalance() const;
    int getPosition() const;
    std::string getCareer() const;
    long getSalary() const;
    std::string getHouse() const;
    long getHousePrice() const;

    // mutators
    void updateBalance(long amount);
    void setPosition(int pos);
    void movePlayer(int steps);
    void updateCareer(const std::string& newJob, long newSalary);
    void updateHouse(const std::string& newHouse, long price);

    // HUD
    void showStatus(const std::string& tileLabel) const;
    void displayHUD() const;
};
#endif