#include "trap.h"

void Trap::process(Player& p){
    p - 20;
}

void Trap::display() const{
    cout << "X";
}

ostream& operator<<(ostream& os, const Trap& t){
    os << "X";
    return os;
}