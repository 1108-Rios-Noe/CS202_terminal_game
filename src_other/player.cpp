#include <iostream>
#include "player.h"
#include "game.h"
#include "emptySpace.h"

Player::Player(){
    health = 100;
    treasureCount = 0;
}

Player::Player(int h, int t, int x_, int y_){
    health = h;
    treasureCount = t;
    x = x_;
    y = y_;
}
Player::Player(const Player& p){
    health = p.health;
    treasureCount = p.treasureCount;
    x = p.x;
    y = p.y;
}

int Player::getX(){
    return x;
}

int Player::getY(){
    return y;
}

int Player::getHealth(){
    return health;
}

int Player::getTreasureCount(){
    return treasureCount;
}

void Player::setX(int x_){
    x = x_;
}

void Player::setY(int y_){
    y = y_;
}

void Player::setHealth(int h){
    health = h;
}

void Player::setTreasureCount(int t){
    treasureCount = t;
}

void Player::move(char dir, Game &g){
    int nx = x, ny = y;
    switch (dir){
        case 'W':
            ny--;
        break;
        case 'A':
            nx--;
        break;
        case 'S':
            ny++;
        break;
        case 'D':
            nx++;
        break;
        default:
            cout << "Use W/A/S/D!\n";
        break;
    }
    // if (dir == 'W')
    //     ny--;
    // else if (dir == 'A')
    //     nx--;
    // else if (dir == 'S')
    //     ny++;
    // else if (dir == 'D')
    //     nx++;
    // else{
    //     cout << "Use W/A/S/D!\n";
    //     return;
    // }

    if (nx < 0 || nx >= g.getSize() || ny < 0 || ny >= g.getSize()){
        cout << "Cannot move outside the board!\n";
        return;
    }
    x = nx;
    y = ny;
    GridElement* e = g.getBoard()->operator[](y)->operator[](x);
    e->process(*this);
    if (e->getType() == TREASURE){
        delete e;
        g.getBoard()->operator[](y)->operator[](x) = new EmptySpace();
    }
    if(e->getType() == TRAP){
        g.setTriggeredTrap(true, x, y);
    }
}

bool Player::isAlive() const{
    return health > 0;
}

bool Player::hasWon() const
{
    return treasureCount >= 3;
}

Player &Player::operator+(int t){
    treasureCount += t;
    return *this;
}

Player &Player::operator-(int d){
    health -= d;
    return *this;
}

ostream &operator<<(ostream &os, const Player &p)
{
    os << "HP:" << p.health << "  Treasures:" << p.treasureCount;
    return os;
}