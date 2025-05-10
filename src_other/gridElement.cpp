#include "gridElement.h"

GridElement::~GridElement(){
    //does nothing as there is nothing to deallocate
}

ostream& operator<<(ostream& os, const GridElement& e) {
    os << e.symbol();
    return os;
}