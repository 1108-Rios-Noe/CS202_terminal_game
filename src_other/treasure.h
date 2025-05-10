#ifndef TREASURE_H
#define TREASURE_H
//
#include "gridElement.h"
// class Player;

//allows for creation of 2d array of gridelement, inherits gridelement
//this creates an element that gives the player +1 treasure
class Treasure : public GridElement {
    int value;

    public:
        Treasure();
        Treasure(int);
        Treasure(const Treasure&);

        void process(Player& p) override;
        char symbol() const override;
        ElementType getType() const override;
};

#endif