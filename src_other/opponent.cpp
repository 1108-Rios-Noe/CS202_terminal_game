#include <iostream>
#include <stdlib.h>
#include "opponent.h"
#include "game.h"
#include "emptySpace.h"

Opponent::Opponent(){
    damage = 30;
}

Opponent::Opponent(int d){
    damage = d;
}
Opponent::Opponent(const Opponent& op){
    damage = op.damage;
}

void Opponent::process(Player &p)
{
    p - damage;
    cout << "You Hit The Opponent! -" << damage << " HP\n";
}

char Opponent::symbol() const{
    return 'O';
}

ElementType Opponent::getType() const
{
    return OPPONENT;
}

void Opponent::moveRandom(Game &g){
    int ox = 0, oy = 0;
    // finds current pos
    for (int i = 0; i < g.getSize(); i++){
        for (int j = 0; j < g.getSize(); j++){
            if (g.getBoard()->operator[](i)->operator[](j) == this){ // g.getBoard()[i][j]; // if ((*g.getBoard())[i]->operator[](j) == this){
                ox = j;
                oy = i;
            }
        }
    }

    int nx, ny;
    do{
        nx = rand() % g.getSize();
        ny = rand() % g.getSize();
    } while ((nx == g.getPlayer()->getX() && ny == g.getPlayer()->getY()) || g.getBoard()->operator[](ny)->operator[](nx)->getType() != EMPTY);

    delete g.getBoard()->operator[](ny)->operator[](nx);
    g.getBoard()->operator[](ny)->operator[](nx) = this;
    g.getBoard()->operator[](oy)->operator[](ox) = new EmptySpace();

    // cout << "Opponent moved.\n"; //debugging pruposes
}