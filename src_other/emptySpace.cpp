#include "emptySpace.h"

EmptySpace::EmptySpace() {}

void EmptySpace::process(Player& p) {
    //dos nothing to player as its empty space
}

char EmptySpace::symbol() const {
    return '.';
}

ElementType EmptySpace::getType() const {
    return EMPTY;
}