#include <iostream>
#include "treasure.h"
#include "player.h"

Treasure::Treasure() {
    value = 1;
}

Treasure::Treasure(int v){
    value = v;
}
Treasure::Treasure(const Treasure& tr){
    value = tr.value;
}

void Treasure::process(Player& p) {
    p + value;
    cout << "Found Treasure! +" << value << "\n";
}

char Treasure::symbol() const {
    return 'T';
}

ElementType Treasure::getType() const {
    return TREASURE;
}