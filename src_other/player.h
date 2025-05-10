#ifndef PLAYER_H
#define PLAYER_H
//
// #include "game.h"
#include <iostream>
using namespace std;
//include game.h throws some errors so forwarding Game class fixes it
class Game;

//this stores the player information such as its position, health, treasurescount and allows for movement
//also checks for status of game
class Player {
    int health;
    int treasureCount;
    int x;
    int y;

    public:
        Player();
        Player(int, int, int, int);
        Player(const Player&);

        int getHealth();
        int getTreasureCount();
        int getX();
        int getY();

        void setX(int);
        void setY(int);
        void setHealth(int);
        void setTreasureCount(int);

        void move(char dir, Game& g);
        bool isAlive() const;
        bool hasWon() const;

        Player& operator+(int t);
        Player& operator-(int d);

        friend ostream& operator<<(ostream& os, const Player& p);
};

#endif