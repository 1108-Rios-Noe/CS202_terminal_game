#include "treasure.h"

void Treasure::process(Player& p){
    p + 1;
}

void Treasure::display() const{
    cout << "T";
}

ostream& operator<<(ostream& os, const Treasure& t){
    os << "T";
    return os;
}