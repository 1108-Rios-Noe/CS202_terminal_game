#include "player.h"

Player::Player(){
    health = 100;
    treasureCount = 0;
    x = 0;
    y = 0;
}

Player::Player(int health_, int treasureCount_, int x_, int y_){
    health = health_;
    treasureCount = treasureCount_;
    x = x_;
    y = y_;
}

Player::Player(const Player& other){
    health = other.health;
    treasureCount = other.treasureCount;
    x = other.x;
    y = other.y;
}

Player::~Player(){
    //Destructor
}

int Player::getHealth() const{
    return health;
}

int Player::getTreasureCount() const{
    return treasureCount;
}

int Player::getX() const{
    return x;
}

int Player::getY() const{
    return y;
}

void Player::setHealth(int health_){
    health = health_;
}

void Player::setTreasureCount(int treasureCount_){
    treasureCount = treasureCount_;
}

void Player::setX(int x_){
    x = x_;
}

void Player::setY(int y_){
    y = y_;
}

void Player::move(char direction, Game& game){
    int newX = x;
    int newY = y;

    switch(direction){
        case 'w':
            newY--;
            break;
        case 's':
            newY++;
            break;
        case 'a':
            newX--;
            break;
        case 'd':
            newX++;
            break;
        default:
            cout << "Invalid move" << endl;
            return;
    }

    if(newX < 0 || newX >= game.getBoard()->getSize() || newY < 0 || newY >= game.getBoard()->getSize()){
        cout << "Invalid move" << endl;
        return;
    }

    x = newX;
    y = newY;

    game.getBoard()->getDataXY(x, y)->process(*this);
}

Player& Player::operator+(int treasure){
    treasureCount += treasure;
    return *this;
}

Player& Player::operator-(int damage){
    health -= damage;
    return *this;
}

bool Player::isAlive() const{
    return health > 0;
}

bool Player::hasWon() const{
    return treasureCount >= 3;
}

ostream& operator<<(ostream& os, const Player& p){
    os << "Health: " << p.health << " | Treasures: " << p.treasureCount << endl;
    return os;
}

