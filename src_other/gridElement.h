#ifndef GRIDELEMENT_H
#define GRIDELEMENT_H
//
#include <iostream>
#include "player.h"
using namespace std;
// class Player;
//enum for the types that gridlement can be
enum ElementType { EMPTY, TRAP, TREASURE, OPPONENT };

//this is an abstract class almost an interface but it has an insertion operator overload
//base class for the element types allowing for a 2d array of gridelement which would be traps, treasures, etc.
class GridElement {
    public:
        virtual void process(Player& p) = 0;
        virtual char symbol() const = 0;
        virtual ElementType getType() const = 0;

        virtual ~GridElement();

        friend ostream& operator<<(ostream& os, const GridElement& e);
};

#endif