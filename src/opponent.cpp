#include "opponent.h"

Opponent::Opponent(){
    x = 0;
    y = 0;
}

Opponent::Opponent(int x_, int y_){
    x = x_;
    y = y_;
}

Opponent::Opponent(const Opponent& other){
    x = other.x;
    y = other.y;
}

void Opponent::process(Player& p){
    p - 30;
}

void Opponent::display() const{
    cout << "O";
}

ostream& operator<<(ostream& os, const Opponent& opp){
    os << "O";
    return os;
}

//Checks if the opponent is in the same position as the player else moves to random location
void Opponent::moveRandom(Game& game){
    srand(NULL);
    int newX = rand() % 5;
    int newY = rand() % 5;

    if (newX == game.getPlayer()->getX() && newY == game.getPlayer()->getY()) {
        // If it is, move to a different random position
        do {
            newX = rand() % 5;
            newY = rand() % 5;
        } while (newX == game.getPlayer()->getX() && newY == game.getPlayer()->getY());
    }
    x = newX;
    y = newY;
}