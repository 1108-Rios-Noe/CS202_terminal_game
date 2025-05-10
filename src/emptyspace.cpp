#include "emptyspace.h"

void EmptySpace::process(Player& p){
    //Nothing
}

void EmptySpace::display() const{
    cout << " . ";
}

ostream& operator<<(ostream& os, const EmptySpace& e){
    os << " . ";
    return os;
}