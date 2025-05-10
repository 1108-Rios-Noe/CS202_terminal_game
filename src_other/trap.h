#ifndef TRAP_H
#define TRAP_H
//
#include "gridElement.h"
// class Player;

//allows for creation of 2d array while implementing an object that deals damage to the player
//inherits from gridelement
class Trap : public GridElement {
    int damage;
public:
    Trap();
    Trap(int);
    Trap(const Trap&);

    void process(Player& p) override;
    char symbol() const override;
    ElementType getType() const override;
};

#endif