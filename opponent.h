#ifndef OPPONENT_H
#define OPPONENT_H

#include <iostream>
using namespace std;


class Opponent : public GridElement{
    int x, y;
    int damage;

    public:
        Player();
        Player(int health, int treasureCount, int x, int y);
        Player(const Player& other);
        ~Player();

        
};

#endif