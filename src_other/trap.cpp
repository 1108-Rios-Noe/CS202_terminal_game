#include <iostream>
#include "trap.h"
#include "player.h"

Trap::Trap() {
    damage = 20;
}

Trap::Trap(int d){
    damage = d;
}
Trap::Trap(const Trap& t){
    damage = t.damage;
}

void Trap::process(Player& p) {
    p - damage;
    cout << "You Hit A Trap! -" << damage << " HP\n";
}

char Trap::symbol() const {
    return 'X';
}

ElementType Trap::getType() const {
    return TRAP;
}