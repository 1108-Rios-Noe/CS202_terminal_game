#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include <iostream>
using namespace std;

class Player{
    int health;
    int treasureCount;
    int x, y;

    public:
        Player();
        Player(int health, int treasureCount, int x, int y);
        Player(const Player& other);
        ~Player();

        int getHealth() const;
        int getTreasureCount() const;
        int getX() const;
        int getY() const;

        void setHealth(int health);
        void setTreasureCount(int treasureCount);
        void setX(int x);
        void setY(int y);

        void move(char, Game&);

        Player& operator+(int);
        Player& operator-(int);

        bool isAlive() const;
        bool hasWon() const;

        friend ostream& operator<<(ostream&, const Player&);
        
};

#endif