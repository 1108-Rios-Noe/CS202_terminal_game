#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H
//
#include "gridElement.h"
//inherits the GridELement class allowing for the making of board as type GridElement
//This class allows for the making of empty spaces
class EmptySpace : public GridElement {
    public:
        EmptySpace();
        void process(Player& p) override;
        char symbol() const override;
        ElementType getType() const override;
};

#endif